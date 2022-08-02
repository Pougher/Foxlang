#pragma once

#include <map>
#include <set>
#include <string>

#include "token.hpp"

/* std::map to contain all strings for tokens and their `Token_t`
 * counterparts. Useful for converting an std::string to a list of
 * tokens. */
static const std::map<const std::string, Token_t> FOX_KEYWORDS = {
    { "while",      Token_t(TokenType_t::TK_WHILE)      },
    { "for",        Token_t(TokenType_t::TK_FOR)        },
    { "if",         Token_t(TokenType_t::TK_IF)         },
    { "elif",       Token_t(TokenType_t::TK_ELIF)       },
    { "else",       Token_t(TokenType_t::TK_ELSE)       },
    { "struct",     Token_t(TokenType_t::TK_STRUCT)     },
    { "assert",     Token_t(TokenType_t::TK_ASSERT)     },
    { "static",     Token_t(TokenType_t::TK_STATIC)     },
    { "const",      Token_t(TokenType_t::TK_CONST)      },
    { "inline",     Token_t(TokenType_t::TK_INLINE)     },
    { "volatile",   Token_t(TokenType_t::TK_VOLATILE)   },
    { "union",      Token_t(TokenType_t::TK_UNION)      },
    { "and",        Token_t(TokenType_t::TK_AND)        },
    { "or",         Token_t(TokenType_t::TK_OR)         },
    { "xor",        Token_t(TokenType_t::TK_XOR)        },
    { "not",        Token_t(TokenType_t::TK_NOT)        },
    { "object",     Token_t(TokenType_t::TK_OBJECT)     },
    { "let",        Token_t(TokenType_t::TK_LET)        },
    { "fn",         Token_t(TokenType_t::TK_FN)         },
    { "namespace",  Token_t(TokenType_t::TK_NAMESPACE)  },
    { "extern",     Token_t(TokenType_t::TK_EXTERN)     },
    { "function",   Token_t(TokenType_t::TK_FN_EXT)     },
    { "variable",   Token_t(TokenType_t::TK_VR_EXT)     },
    { "library",    Token_t(TokenType_t::TK_LIB_EXT)    },
    { "return",     Token_t(TokenType_t::TK_RETURN)     },
    /* not strictly keywords */
    { "(",          Token_t(TokenType_t::TK_LPAREN)     },
    { ")",          Token_t(TokenType_t::TK_RPAREN)     },
    { "{",          Token_t(TokenType_t::TK_LCPAREN)    },
    { "}",          Token_t(TokenType_t::TK_RCPAREN)    },
    { "[",          Token_t(TokenType_t::TK_LSPAREN)    },
    { "]",          Token_t(TokenType_t::TK_RSPAREN)    },
    { ".",          Token_t(TokenType_t::TK_DOT)        },
    { ",",          Token_t(TokenType_t::TK_COMMA)      },
    { ";",          Token_t(TokenType_t::TK_SEMICOLON)  },
    { "|",          Token_t(TokenType_t::TK_LITERAL_OR) },
    { "^",          Token_t(TokenType_t::TK_LITERAL_XOR)},
    { "&",          Token_t(TokenType_t::TK_AMPERSAND  )},
    { "~",          Token_t(TokenType_t::TK_LITERAL_NOT)},
    { "+",          Token_t(TokenType_t::TK_PLUS)       },
    { "-",          Token_t(TokenType_t::TK_MINUS)      },
    { "/",          Token_t(TokenType_t::TK_DIVIDE)     },
    { "=",          Token_t(TokenType_t::TK_EQUALS)     },
    { ":",          Token_t(TokenType_t::TK_COLON)      },
    { "%",          Token_t(TokenType_t::TK_MODULO)     },
    { ">",          Token_t(TokenType_t::TK_GREATER)    },
    { "<",          Token_t(TokenType_t::TK_LESS)       },
    { "*",          Token_t(TokenType_t::TK_MULTIPLY)   }
};

static std::set<std::string> FOX_TYPES {
    "i64",
    "i32",
    "i16",
    "i8",
    "u64",
    "u32",
    "u16",
    "u8",
    "char",
    "bool",
    "f64",
    "f32",
    "char",
    "void"
};
