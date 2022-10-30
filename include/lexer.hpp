#pragma once

#include <vector>
#include <iostream>
#include <map>
#include <set>

#include "token.hpp"
#include "keywords.hpp"
#include "lexer_action.hpp"
#include "error.hpp"
#include "action_string.hpp"
#include "action_number.hpp"
#include "action_char.hpp"
#include "state.hpp"
#include "common.hpp"

/* Lexer class. Controls lexical analysis which
 * is responsible for converting a file into a
 * list of tokens. */

class Lexer_t {
public:
    /* constructor to initialize all parts of the lexer */
    Lexer_t(std::string& file);
    ~Lexer_t();     /* destructor */
    void lex();     /* performs lexical analysis */
    /* checks if a specific value is a keyword */
    void keyword(const std::string& kw, Token_t tk, char n);
    /* loops through an std::map of keywords and checks if `this->m_toks` is a
     * keyword using the `keyword()` function. */
    void keyword_mapcheck(const std::map<const std::string, Token_t>& kw,
        char n);
    /* checks if `m_toks` is the name of a type */
    void type_veccheck(std::set<std::string>& types, char n);
    /* removes the delimiter on the end of a string. If a delimiter is found,
     * return it. Otherwise, return 0. */
    char remove_delimiter(std::string& s);
    /* returns the tokens stored within the lexer class */
    std::vector<Token_t>& extract();
    /* removes asterisks from the end of a string */
    std::string remove_asterisks(const std::string& str);
private:
    std::vector<Token_t> m_tokens;  /* tokens list to store all tokens */
    std::string m_file;     /* file data to be analysed */
    std::string m_toks;     /* string object for keeping track of text */
    /* string object for keeping track of text with spaces */
    std::string m_ftoks;
    /* std::vector of all action classes */
    std::vector<LexerAction_t*> m_actions;
    State_t<bool> m_state;  /* the current state of the lexer */
};
