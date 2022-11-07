#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <tuple>

#include "token.hpp"
#include "scope.hpp"
#include "expected_tokens.hpp"
#include "file.hpp"
#include "common.hpp"
#include "error.hpp"
#include "brace_stack.hpp"
#include "error_messages.hpp"

/* Linear parser to parse tokens and construct C code */
class Parser_t {
public:
    /* constructor */
    Parser_t(std::vector<Token_t>& tokens, const std::string& filename);
    void parse();       /* Parse method. Parses tokens */
    void write();       /* write `c_program` to file */
    void push_newline();/* pushes a complete newline string to `c_program` */

    /* checks if the scope node `type` has an object type of `o_type` */
    bool is_object(const std::string& type, ObjectType_t o_type);

    /* function to validate the token stream */
    std::vector<Token_t*> expect(
            unsigned long* i,
            const std::vector<TokenType_t>& expected,
            const std::string& error,
            bool err = true,
            bool* success = nullptr
    );

    /* function to visit the ith token */
    const Token_t& visit_token(uint64_t i);
    /* function to construct a C type specifier based upon a token */
    std::string produce_type(Token_t& token);
    /* function to setup the parser to produce another language's code from
     * the file extension */
    void set_language(const std::string& extension);
    /* sets the default C code for the program */
    void set_default_c(const std::string& c);
private:
    /* Variable that contains all of the tokens to be parsed */
    std::vector<Token_t> m_tokens;
    std::string c_program;      /* the finished C program */
    std::string c_buffer;       /* buffer to hold the program temporarily */
    std::string c_filename;     /* filename of the C program */
    std::string language;       /* sets the programming language */
    Scope_t m_scope;            /* scope tree for all variables */
    uint64_t m_line;            /* variable to store the current line number */
    /* the current indentation level of the C program */
    int64_t m_indent_level;
    BraceStack_t m_bracestack;  /* stack to contain all braces */
    bool m_array;               /* array active */
};
