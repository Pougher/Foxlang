#pragma once

#include <string>
#include <iostream>
#include <cwchar>

#include "lexer_action.hpp"

class ActionChar_t : public LexerAction_t {
public:
    /* constructor */
    ActionChar_t();
    /* destructor */
    ~ActionChar_t();
    /* override of parent class */
    void update(toks_t toks, State_t<bool>& state, std::vector<Token_t>& tokens,
                char current_char);
private:
    /* variable for storing the current character */
    std::string m_expr;
};
