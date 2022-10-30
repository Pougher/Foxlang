#pragma once

#include <string>

namespace ErrorMessage {
    const std::string VARIABLE_LET_ERROR = "Variable let declaration requires "
        "an identifier, a type and an assignment";
    const std::string VARIABLE_NAMESPACE_NAKED_ERROR = "Cannot define a"
        "variable naked under a namespace";
    const std::string IDENTIFIER_ALREADY_DECLARED_ERROR(
        const std::string& name);
    const std::string NAMESPACE_IDENT_NOT_FOUND(
        const std::string& name);
    const std::string IDENT_NOT_IN_NAMESPACE(const std::string& name,
        const std::string& child_name);
    const std::string VAR_DECL_WITHOUT_LET = "Variable declaration without `let"
        "` outside function definition";
    const std::string IDENT_NOT_DEFINED(const std::string& name);
    const std::string UNEXPECTED_EOF = "Unexpected EOF while parsing tokens";
    const std::string EXPECTED_IDENT_AFTER_FN = "Expected indentifier after "
        "`fn` in function definition";
    const std::string FUNC_DEF_REQUIRES = "Operator `-> [typename]` required "
        "for complete function definition";
    const std::string UNEXPECTED_TOKEN = "Unexpected token while parsing";
    const std::string ONLY_IN_EXTERN_BLOCKS(const std::string& name);
    const std::string STRAY_WITHOUT(char brack);
    const std::string STRUCT_EXPECT_IDENT = "Struct expected an identifier "
        "followed by a curly brace";
    const std::string UNION_EXPECT_IDENT = "Union expected an identifier"
        " followed by a curly brace";
    // NAMESPACE_EXPECT_IDENTIFIER_AND_THEN_OPENING_CURLY_BRACE
    const std::string NAMESPACE_EXP_IDENT_OC = "Namespace expected an "
        "identifier and then an opening curly brace";
    const std::string UNMATCHED_IN_FILE(const std::string& brace);
    const std::string CHAR_LITERAL_TOO_LARGE = "Character literals can only be "
        "one character large";
}
