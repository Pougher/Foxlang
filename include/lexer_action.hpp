#pragma once

#include <string>

#include "state.hpp"
#include "token.hpp"


/* LexerAction class to overridden by a group of sub-classes. The resulting
 * classes may be grouped into the lexer and run on the `toks` variable. Each
 * resulting class has independant control over all of the variables within the
 * lexer, and therefore careful modification is required. */
class LexerAction_t {
public:
    virtual void update(toks_t toks, State_t<bool>& state,
        std::vector<Token_t>& tokens, char current_char) = 0;
    virtual ~LexerAction_t() {}
};
