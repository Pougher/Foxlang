#pragma once

#include <string>
#include <iostream>

#include "lexer_action.hpp"
#include "common.hpp"
#include "token.hpp"

class ActionNumber_t : public LexerAction_t {
public:
    /* constructor */
    ActionNumber_t();
    /* destructor */
    ~ActionNumber_t();
    /* override of parent class */
    void update(toks_t toks, State_t<bool>& state, std::vector<Token_t>& tokens, char current_char);
private:
    std::string m_expr;
};
