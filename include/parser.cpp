#include "parser.hpp"
#include "scope.hpp"

Parser_t::Parser_t(std::vector<Token_t>& tokens, const std::string& filename)
{
    this->m_tokens = std::move(tokens);
    this->c_filename = filename;
    this->c_program = Common::default_c();
    this->m_line = 1; // lines start at one
    this->m_indent_level = 0;
}


void Parser_t::parse()
{
    // iterator
    unsigned long i = 0;
    // number of opening braces to skip
    unsigned long brace_skip = 0;
    // check if a function is being defined
    bool fn_def = false;
    // check if a function is active
    unsigned char fn_active = 0;
    // namespace list
    std::vector<std::string> namespace_list;
    
    while (i < this->m_tokens.size()) {
        Token_t& tok = this->m_tokens[i];
        TokenType_t tok_type = this->m_tokens[i].get_type();

        switch (tok_type) {
            case TK_LET: {
                std::vector<Token_t*> needed = this->expect(
                        &i,
                        PARSER_EXPECT_VARIABLE_DECL,
                        "Variable let declaration requires an identifier, a type and an assignment."
                );
                
                if (this->m_scope.contains_node_up(std::get<std::string>((*needed[0])[0]))) {
                    // variable redefinition error
                    Error::GenericError_nl(
                            "Identifier already declared: '" + \
                            std::get<std::string>((*needed[0])[0]) + "'",
                            REDEF_ERROR,
                            this->m_line
                    );
                }
                
                // check if the variable is being defined naked under a namespace
                if (this->m_bracestack.curly_brace.size() > 0) {
                    if (this->m_bracestack.curly_brace[this->m_bracestack.curly_brace.size() - 1] == Brace_t::NAMESPACE) {
                        Error::GenericError_nl(
                                "Cannot define a variable naked under a namespace",
                                NAMESPACE_ERROR,
                                this->m_line
                        );
                    }
                }

                this->c_program += this->produce_type(*needed[2]) + " " + \
                                   std::get<std::string>((*needed[0])[0]) + " = ";
                
                this->m_scope.add_child(Object_t(
                        std::get<std::string>((*needed[0])[0]),
                        std::get<std::string>((*needed[2])[0]),
                        ObjectType_t::OBJ_TYPE_VAR
                ));
                break;
            }
            case TK_IDENTIFIER: {
                bool func_arg = false;
                
                // check if it is making a call to a namespace attribute
                if (i + 2 < this->m_tokens.size()) {
                    if (this->m_tokens[i + 1].get_type() == TK_COLON && this->m_tokens[i + 2].get_type() == TK_COLON) {
                        std::string namespace_name = "";
                        uint64_t iter = i;
                
                        const std::string begin_scope_id = std::get<std::string>(tok[0]);
                        Object_t* scope_root = this->m_scope.contains_node_up(begin_scope_id);
                        
                        if (scope_root == nullptr) {
                            Error::GenericError_nl(
                                    "Namespace identifier not found: '" + begin_scope_id + "'",
                                    ERROR_SYNTAX,
                                    this->m_line
                            );
                        }

                        this->m_scope.push();
                        this->m_scope.set(scope_root); // center the tree around `scope_root`
                        
                        namespace_name += begin_scope_id;
                        
                        while (iter + 3 < this->m_tokens.size()) {
                            if (this->m_tokens[iter + 1].get_type() == TK_COLON && this->m_tokens[iter + 2].get_type() == TK_COLON &&
                                this->m_tokens[iter + 3].get_type() == TK_IDENTIFIER) {
                                const std::string child_name = std::get<std::string>(this->m_tokens[iter + 3][0]);
                                
                                if (!this->m_scope.traverse(child_name)) {
                                    Error::GenericError_nl(
                                            "Namespace identifier ('" + child_name + "') not found in namespace '" + this->m_scope.get()->name +"'",
                                            ERROR_SYNTAX,
                                            this->m_line
                                    );
                                }
                                
                                namespace_name += "_" + child_name;
                                iter += 3;
                            } else {
                                break;
                            }
                        }
                        
                        this->c_program += namespace_name + this->m_scope.get()->metadata[0];
                        this->m_scope.pop();
                        
                        i = iter + 1;
                        continue;
                    }
                }
                std::vector<Token_t*> function_data = this->expect(
                        &i,
                        PARSER_EXPECT_ARG_DECL,
                        "",
                        false,
                        &func_arg
                );
                                
                if (func_arg) {
                    if (!fn_def && this->m_bracestack.curly_brace_top() != Brace_t::STRUCTURE) {
                        Error::GenericError_nl(
                                "Variable decleration without `let` outside function definition",
                                ERROR_SYNTAX,
                                this->m_line
                        );
                    }
                    
                    this->c_program += this->produce_type(*function_data[1]) + " " + \
                        std::get<std::string>(tok[0]);
                    
                    this->m_scope.add_child(Object_t(
                            std::get<std::string>(tok[0]),
                            std::get<std::string>((*function_data[1])[0]),
                            ObjectType_t::OBJ_TYPE_VAR)
                    );
                } else {
                    this->c_program += std::get<std::string>(tok[0]);
                }
                
                if (this->m_scope.contains_node_up(std::get<std::string>(tok[0])) == nullptr) {
                    Error::GenericError_nl(
                            "Identifier not defined: '" + std::get<std::string>(tok[0]) + "'",
                            ERROR_SYNTAX,
                            this->m_line
                    );
                }
                
                break;
            }
            case TK_FN: {
                if (i + 1 >= this->m_tokens.size()) {
                    Error::GenericError_nl(
                            "Unexpected EOF while parsing tokens",
                            ERROR_EOF,
                            this->m_line
                    );
                }
                Token_t& func_ident = this->m_tokens[i + 1];
                if (func_ident.get_type() != TK_IDENTIFIER) {
                    Error::GenericError_nl(
                            "Expected identifier after `fn` in function definition",
                            ERROR_SYNTAX,
                            this->m_line
                    );
                }
                
                bool found_type_op = false;
                
                Token_t* type_op = nullptr;
                
                for (unsigned long iter = i; i < this->m_tokens.size(); iter++) {
                    if (this->m_tokens[iter].get_type() == TK_LCPAREN) {
                        if (!found_type_op) {
                            std::string error = "Operator `-> [typename]` required for complete"
                                                " function definition";
                            
                            Error::GenericError_nl(error,  ERROR_SYNTAX, this->m_line);
                        }
                    }
                    if (iter + 2 >= this->m_tokens.size()) {
                        Error::GenericError_nl(
                                "Unexpected EOF while parsing tokens",
                                ERROR_EOF,
                                this->m_line
                        );
                    }
                    if (this->m_tokens[iter].get_type() == TK_MINUS && \
                        this->m_tokens[iter + 1].get_type() == TK_GREATER && \
                        this->m_tokens[iter + 2].get_type() == TK_TYPE)
                    {
                        found_type_op = true;
                        type_op = &this->m_tokens[iter + 2];
                        
                        i++; // skip the identifier
                        break;
                    }
                }
                
                if (type_op != nullptr) {
                    // first, check if another identifier of the same name exists
                    if (this->m_scope.contains_node_up(std::get<std::string>(func_ident[0]))) {
                        Error::GenericError_nl(
                                "Identifier already declared: '" + \
                                std::get<std::string>(func_ident[0]) + "'",
                                REDEF_ERROR,
                                this->m_line
                        );
                    }
                    std::string namespace_prefix = "";
                    for (auto& name : namespace_list) {
                        namespace_prefix += name + "_";
                    }
                    
                    if (namespace_list.size() == 0) namespace_prefix = "";
                    // construct the function definition
                    const std::string mangle_str = Common::garbage(10);
                    
                    this->c_program += this->produce_type(*type_op) + " " + \
                        namespace_prefix + std::get<std::string>(func_ident[0]);
                    
                    Object_t function_object(
                            std::get<std::string>(func_ident[0]),
                            std::get<std::string>((*type_op)[0]),
                            ObjectType_t::OBJ_TYPE_FUNC
                    );
                    
                    if (namespace_list.size() > 0) {
                        function_object.metadata.push_back(mangle_str);
                        this->c_program += mangle_str;
                    }
                    
                    this->m_scope.add_child(function_object);
                    this->m_scope.traverse(std::get<std::string>(func_ident[0]));
                    brace_skip++;
                    fn_def = true;
                    fn_active = 3;
                }
                break;
            }
            case TK_EXTERN: {
                if (i + 2 < this->m_tokens.size()) {
                    Token_t& type = this->m_tokens[i + 1];
                    Token_t& iden = this->m_tokens[i + 2];
                    
                    if ((type.get_type() != TK_FN_EXT && type.get_type() != TK_VR_EXT && type.get_type() != TK_LIB_EXT && type.get_type() != TK_TYPE_EXT && type.get_type() != TK_STRUCT_EXT)
                        || (iden.get_type() != TK_IDENTIFIER && iden.get_type() != TK_STRING)) {
                        Error::GenericError_nl(
                                "Unexpected token while parsing",
                                ERROR_SYNTAX,
                                this->m_line
                        );
                    }
                    
                    std::string& identifier = std::get<std::string>(iden[0]);
                    if (type.get_type() == TK_LIB_EXT) {
                        this->c_program += "#include \"" + identifier + "\"";
                        i += 3;
                        continue;
                    }
                    
                    if (this->m_scope.contains_node_up(identifier)) {
                        Error::GenericError_nl(
                                "Identifier already declared: '" + \
                                identifier + "'",
                                REDEF_ERROR,
                                this->m_line
                        );
                    }

                    switch (type.get_type()) {
                        case TK_FN_EXT: {
                            this->m_scope.add_child(
                                    Object_t(identifier, "none", ObjectType_t::OBJ_TYPE_FUNC)
                            );
                            break;
                        }
                        case TK_VR_EXT: {
                            this->m_scope.add_child(
                                    Object_t(identifier, "none", ObjectType_t::OBJ_TYPE_VAR)
                            );
                            break;
                        }
                        case TK_STRUCT_EXT: {
                            this->m_scope.add_child(
                                    Object_t(identifier, "none", ObjectType_t::OBJ_TYPE_STRUCT)
                            );
                            break;
                        }
                        default: { break; }
                    }
                    i += 2;
                } else {
                    Error::GenericError_nl(
                            "Unexpected EOF while parsing tokens",
                            ERROR_EOF,
                            this->m_line
                    );
                }
                break;
            }
            case TK_FN_EXT: {
                Error::GenericError_nl(
                        "Function keyword may only be used in extern blocks",
                        ERROR_SYNTAX,
                        this->m_line
                );
                break;
            }
            case TK_VR_EXT: {
                Error::GenericError_nl(
                        "Variable keyword may only be used in extern blocks",
                        ERROR_SYNTAX,
                        this->m_line
                );
                break;
            }
            case TK_STRING: {
                this->c_program += "\"" + std::get<std::string>(tok[0]) + "\"";
                break;
            }
            case TK_LCPAREN: {
                if (brace_skip) {
                    brace_skip--;
                } else {
                    std::vector<std::string> collected = this->m_scope.collect();
                    std::string scope_name = Common::brace_scope_name(collected);
                    
                    this->m_scope.add_child(Object_t(
                        scope_name,
                        "NONE",
                        ObjectType_t::OBJ_TYPE_PAREN
                    ));
                    
                    this->m_scope.traverse(scope_name);
                }
                if (fn_def) fn_def = false;
                this->m_indent_level++;
                this->c_program += "{";
                this->m_bracestack.curly_brace.push_back(Brace_t::NONE);
                break;
            }
            case TK_RCPAREN: {
                this->m_indent_level--;
                if (this->m_indent_level < 0 || this->m_bracestack.curly_brace.size() == 0) {
                    Error::GenericError_nl(
                            "Stray '}' without matching '{'",
                            BRACE_ERROR,
                            this->m_line
                    );
                }

                this->m_scope.traverse_back();
                if (this->m_bracestack.curly_brace_top() == Brace_t::NAMESPACE) {
                     namespace_list.pop_back();
                } else {
                    this->c_program += "}";
                }
                this->m_bracestack.curly_brace.pop_back();
                break;
            }
            case TK_LSPAREN: {
                this->m_bracestack.square_brace.push_back(Brace_t::NONE);
                this->c_program += "[";
                break;
            }
            case TK_RSPAREN: {
                if (this->m_bracestack.square_brace.size() == 0) {
                    Error::GenericError_nl(
                            "Stray ']' without matching '['",
                            BRACE_ERROR,
                            this->m_line
                    );
                }
                this->m_bracestack.square_brace.pop_back();
                this->c_program += "]";
                break;
            }
            case TK_LPAREN: {
                this->m_bracestack.brace.push_back(Brace_t::NONE);
                this->c_program += "(";
                break;
            }
            case TK_RPAREN: {
                if (this->m_bracestack.brace.size() == 0) {
                    Error::GenericError_nl(
                            "Stray ')' without matching '('",
                            BRACE_ERROR,
                            this->m_line
                    );
                }
                this->m_bracestack.brace.pop_back();
                this->c_program += ")";
                break;
            }
            case TK_COMMA: { this->c_program += ", "; break; }
            case TK_NEWLINE: {
                bool ignore = false;
                if (i + 1 < this->m_tokens.size()) {
                    if (this->m_tokens[i + 1].get_type() == TK_RCPAREN) {
                        this->push_newline();
                        for (auto z = 0; z < 4; z++) this->c_program.pop_back();
                        ignore = true;
                    }
                }
                if (!ignore) {
                    this->m_line++;
                    this->push_newline();
                }
                break;
            }
            case TK_SEMICOLON: { this->c_program += ";"; break; }
            case TK_NUMBER: {
                this->c_program += std::get<std::string>(tok[0]);
                break;
            }
            case TK_CONST: { this->c_program += "const "; break; }
            case TK_STATIC: { this->c_program += "static "; break; }
            case TK_VOLATILE: { this->c_program += "volatile "; break; }
            case TK_FOR: { this->c_program += "for "; break; }
            case TK_WHILE: { this->c_program += "while "; break; }
            case TK_IF: { this->c_program += "if "; break; }
            case TK_ELIF: { this->c_program += "else if "; break; }
            case TK_ELSE: { this->c_program += "else "; break; }
            case TK_RETURN: { this->c_program += "return "; break; }
            case TK_EQUALS: { this->c_program += "="; break; }
            case TK_AMPERSAND: { this->c_program += "&"; break; }
            case TK_OR: { this->c_program += "|"; break; }
            case TK_XOR: { this->c_program += "^"; break; }
            case TK_NOT: { this->c_program += "!"; break; }
            case TK_GREATER: {
                if (fn_active) {
                    fn_active--;
                    break;
                }
                this->c_program += ">"; break;
            }
            case TK_LESS: { this->c_program += "<"; break; }
            case TK_PLUS: { this->c_program += "+"; break; }
            case TK_MINUS: {
                if (fn_active) {
                    fn_active--;
                    break;
                }
                
                if (i + 2 < this->m_tokens.size()) {
                    if (this->m_tokens[i + 1].get_type() == TK_GREATER && this->m_tokens[i + 2].get_type() == TK_IDENTIFIER) {
                        // ignore identifier existence
                        this->c_program += "->" + std::get<std::string>(this->m_tokens[i + 2][0]);
                        i += 3;
                        continue;
                    }
                }
                this->c_program += "-";
                break;
            }
            case TK_TYPE: {
                if (fn_active) {
                    fn_active--;
                    break;
                }

                this->c_program += this->produce_type(tok);
                break;
            }
            case TK_DIVIDE: { this->c_program += "/"; break; }
            case TK_MULTIPLY: { this->c_program += "*"; break; }
            case TK_STRUCT: {
                std::vector<Token_t*> expected = this->expect(
                        &i,
                        PARSER_EXPECT_STRUCTURE,
                        "Struct expected an identifier followed by a curly brace"
                );
                const std::string name = std::get<std::string>((*expected[0])[0]);
                this->c_program += "struct " + name + "{";
                
                this->m_scope.add_child(Object_t(name, "struct", OBJ_TYPE_STRUCT));
                this->m_scope.traverse(name);
                this->m_indent_level++;
                
                this->m_bracestack.curly_brace.push_back(Brace_t::STRUCTURE);
                break;
            }
            case TK_UNION: {
                std::vector<Token_t*> expected = this->expect(
                        &i,
                        PARSER_EXPECT_STRUCTURE,
                        "Union expected an identifier followed by a curly brace"
                );
                const std::string name = std::get<std::string>((*expected[0])[0]);
                this->c_program += "union " + name + "{";
                
                this->m_scope.add_child(Object_t(name, "union", OBJ_TYPE_UNION));
                this->m_scope.traverse(name);
                this->m_indent_level++;
                 
                this->m_bracestack.curly_brace.push_back(Brace_t::STRUCTURE);
                break;                
            }
            case TK_NAMESPACE: {
                if (i + 2 < this->m_tokens.size()) {
                    if (this->m_tokens[i + 1].get_type() != TK_IDENTIFIER || 
                        this->m_tokens[i + 2].get_type() != TK_LCPAREN) {
                        Error::GenericError_nl(
                                "Namespace expected an identifier and then an opening curly brace",
                                ERROR_SYNTAX,
                                this->m_line
                        );
                    }
                    std::string& ident = std::get<std::string>(this->m_tokens[i + 1][0]);
                    
                    if (this->m_scope.contains_node_up(ident)) {
                        Error::GenericError_nl(
                                "Identifier already declared: '" + \
                                ident + "'",
                                REDEF_ERROR,
                                this->m_line
                        );
                    }
                    
                    this->m_scope.add_child(Object_t(ident, "none", ObjectType_t::OBJ_TYPE_NAMESPACE));
                    this->m_scope.traverse(ident);
                    
                    namespace_list.push_back(ident);
                    this->m_bracestack.curly_brace.push_back(Brace_t::NAMESPACE);
                    this->m_indent_level ++;
                    i += 2;
                } else {
                    Error::GenericError_nl(
                            "Unexpected EOF while parsing tokens",
                            ERROR_EOF,
                            this->m_line
                    );
                }
                break;
            }
            
            case TK_DOT: {
                if (i + 1 < this->m_tokens.size()) {
                    if (this->m_tokens[i + 1].get_type() == TK_IDENTIFIER) {
                        // no checking on identifier validation
                        this->c_program += "." + std::get<std::string>(this->m_tokens[i + 1][0]);
                        i += 2;
                        continue;
                    }
                }
                this->c_program += ".";
                break;
            }

            default: {
                std::cout << "Token type not understood: " << tok.get_type() << std::endl;
                break;
            }
        }
        i ++;
    }

    if (this->m_bracestack.curly_brace.size() > 0) {
        Error::GenericError_nl(
                "Unmatched curly braces in file",
                BRACE_ERROR,
                0
        );
    }

    if (this->m_bracestack.square_brace.size() > 0) {
        Error::GenericError_nl(
                "Unmatched square braces in file",
                BRACE_ERROR,
                0
        );
    }

    if (this->m_bracestack.brace.size() > 0) {
        Error::GenericError_nl(
                "Unmatched braces in file",
                BRACE_ERROR,
                0
        );
    }

    this->m_scope.free();
}

void Parser_t::write()
{
    File::write_file(this->c_filename, this->c_program);
}

std::vector<Token_t*> Parser_t::expect(
        unsigned long* i,
        const std::vector<TokenType_t>& expected,
        const std::string& error,
        bool err,
        bool* success)
{
    unsigned long original_i = *i;
    std::vector<Token_t*> found;
    (*i) ++;

    if ((*i + expected.size() + 1) >= this->m_tokens.size()) {
        Error::GenericError_nl(
                "Unexpected EOF while parsing tokens",
                ERROR_EOF,
                this->m_line
        );
    }
    for (auto el : expected) {
        if (el == this->m_tokens[*i].get_type()) {
            found.push_back(&this->m_tokens[*i]);
            (*i)++;
        } else {
            if (!err) {
                *success = false;
                *i = original_i;
                return std::vector<Token_t*>();
            }
            std::cerr << ERROR_SYNTAX << " on line " << this->m_line << std::endl;;
            std::cerr << "    " << error << std::endl;
            std::exit(1);
        }
    }

    (*i)  --;
    if (success != nullptr) *success = true;

    return found;
}

const Token_t& Parser_t::visit_token(uint64_t i)
{
    if (i >= this->m_tokens.size()) {
        Error::GenericError_nl(
                "Unexpected EOF while parsing tokens",
                ERROR_EOF,
                this->m_line
        );
    }
    return this->m_tokens[i];
}

void Parser_t::push_newline()
{
    this->c_program += "\n" + std::string(this->m_indent_level * 4, ' ');
}

bool Parser_t::is_object(const std::string& type, ObjectType_t o_type)
{
    Object_t* contained_obj = this->m_scope.contains_node_up(type);
    if (contained_obj != nullptr) {
        return (contained_obj->obj_type == o_type);
    }
    return false;
}

std::string Parser_t::produce_type(Token_t& token)
{
    std::string type_name = "";
    long asterisks = std::get<long>(token[1]);
    
    const std::string type = std::get<std::string>(token[0]);
    
    if (this->is_object(type, ObjectType_t::OBJ_TYPE_STRUCT)) {
        type_name += "struct ";
    } else if (this->is_object(type, ObjectType_t::OBJ_TYPE_UNION)) {
        type_name += "union ";
    }
    
    type_name += type; // the identifier
    
    while (asterisks--) {
        type_name += "*";
    }
    
    return type_name;
}
