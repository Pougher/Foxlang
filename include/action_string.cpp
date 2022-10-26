#include "action_string.hpp"

ActionString_t::~ActionString_t() {}

ActionString_t::ActionString_t()
{
    // init.
    this->m_expr = "";
}

void ActionString_t::update(toks_t toks, State_t<bool>& state,
    std::vector<Token_t>& tokens, char current_char)
{
    if (!state["any_active"] && current_char == '"') {
        state.set("any_active", true);
        state.set("string_active", true);
        toks.first = "";
        toks.second = "";
        this->m_expr = "";
    } else if (state["string_active"] && current_char != '"') {
        this->m_expr += current_char;
        toks.first = "";
        toks.second = "";
    } else if (state["string_active"]) {
        tokens.push_back(make_token(TokenType_t::TK_STRING, this->m_expr));
        state.set("any_active", false);
        state.set("string_active", false);
        toks.first = "";
        toks.second = "";
    }
}
