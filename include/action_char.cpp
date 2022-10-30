
#include "action_char.hpp"

ActionChar_t::~ActionChar_t() {}

ActionChar_t::ActionChar_t()
{
    // init.
    this->m_expr = "";
}

void ActionChar_t::update(toks_t toks, State_t<bool>& state,
    std::vector<Token_t>& tokens, char current_char)
{
    if (!state["any_active"] && current_char == '\'') {
        state.set("any_active", true);
        state.set("char_active", true);

        toks.first = "";
        toks.second = "";

        this->m_expr = "";
    } else if (state["char_active"] && current_char != '\'') {
        this->m_expr += current_char;
        toks.first = "";
        toks.second = "";
    } else if (state["char_active"]) {
        tokens.push_back(make_token(TokenType_t::TK_CHAR, this->m_expr));
        state.set("any_active", false);
        state.set("char_active", false);
        toks.first = "";
        toks.second = "";
    }
}
