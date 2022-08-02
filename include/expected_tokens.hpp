#pragma once

#include <vector>
#include <iostream>

#include "token.hpp"

/* expected values for a let statement */
static const std::vector<TokenType_t> PARSER_EXPECT_VARIABLE_DECL {
    TK_IDENTIFIER,
    TK_COLON,
    TK_TYPE,
    TK_EQUALS 
};

/* expected values for a function argument definition */
static const std::vector<TokenType_t> PARSER_EXPECT_ARG_DECL {
    TK_COLON,
    TK_TYPE
};

/* expected values for structs and unions */
static const std::vector<TokenType_t> PARSER_EXPECT_STRUCTURE {
    TK_IDENTIFIER,
    TK_LCPAREN
};