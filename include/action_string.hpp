#pragma once

#include <string>
#include <iostream>

#include "lexer_action.hpp"

class ActionString_t : public LexerAction_t {
public:
    /* constructor */
    ActionString_t();
    /* destructor */
    ~ActionString_t();
    /* override of parent class */
    void update(toks_t toks, State_t<bool>& state, std::vector<Token_t>& tokens, char current_char);
private:
    /* variable for storing the current string data */
    std::string m_expr;
};
