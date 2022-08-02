#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <functional>
#include <variant>
#include <cstdint>
#include <cstdlib>

/* Enum containing all aliases for various token
 * types. */
typedef enum {
    TK_NONE,
    TK_WHILE,
    TK_FOR,
    TK_IF,
    TK_ELIF,
    TK_ELSE,
    TK_STRUCT,
    TK_ASSERT,
    TK_STATIC,
    TK_CONST,
    TK_INLINE,
    TK_VOLATILE,
    TK_UNION,
    TK_AND,
    TK_OR,
    TK_XOR,
    TK_NOT,
    TK_STRING,
    TK_OBJECT,
    TK_TYPE,
    TK_LPAREN,
    TK_RPAREN,
    TK_LCPAREN,
    TK_RCPAREN,
    TK_LSPAREN,
    TK_RSPAREN,
    TK_DOT,
    TK_COMMA,
    TK_SEMICOLON,
    TK_LITERAL_OR,
    TK_LITERAL_XOR,
    TK_LITERAL_NOT,
    TK_AMPERSAND,
    TK_PLUS,
    TK_MINUS,
    TK_MULTIPLY,
    TK_DIVIDE,
    TK_COLON,
    TK_MODULO,
    TK_NUMBER,
    TK_IDENTIFIER,
    TK_EQUALS,
    TK_NEWLINE,
    TK_LET,
    TK_FN,
    TK_GREATER,
    TK_LESS,
    TK_NAMESPACE,
    TK_EXTERN,
    TK_FN_EXT,
    TK_VR_EXT,
    TK_LIB_EXT,
    TK_RETURN,
    TK_STRUCT_EXT,
    TK_TYPE_EXT
} TokenType_t;

/* Type id locations for reference later in code */
#define LONG_TYPE_ID     0
#define DOUBLE_TYPE_ID   1
#define STRING_TYPE_ID   2
#define BOOL_TYPE_ID     3
#define VOID_PTR_TYPE_ID 4

using tk_variant_t = std::variant<long, double, std::string, bool, void*>;
using toks_t = std::pair<std::string&, std::string&>;

/* Class which stores token data, uses an std::variant
 * to store the data. */

class Token_t {
public:
    Token_t(TokenType_t t);                  /* sets the type of the token */
    std::vector<tk_variant_t>& get_data();   /* m_data getter */
    void set_type(TokenType_t t);            /* m_type setter */
    TokenType_t& get_type();                 /* m_type getter */

    tk_variant_t& operator[](int i)
    {
        return this->m_data[i];
    }

    void print();                           /* function to print all token data */
private:
    /* Heterogeneous std::vector for storing data.
     * void* is for pointers to token lore objects. */
    std::vector<tk_variant_t> m_data;

    /* Member that stores the internal type of the
     * token. */
    TokenType_t m_type;
};

/* Function to initialize the token class with any amount of
 * data due to parameter packing `m_data`. Also initializes the
 * `m_type` variable with the desired token type. */
template<typename... T>
Token_t make_token(TokenType_t tk_type, T... args)
{
    Token_t new_token(tk_type);
    new_token.get_data().emplace_back(args...);

    return new_token;
}

/* constructs an std::pair of values made up of the two arguments
 * passed */
inline toks_t construct_toks_t(std::string& toks, std::string& ftoks)
{
    return toks_t { toks, ftoks };
}
