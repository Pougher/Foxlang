#include "action_number.hpp"
#include "keywords.hpp"

ActionNumber_t::~ActionNumber_t() {}

ActionNumber_t::ActionNumber_t()
{
    // init.
    this->m_expr = "";
}

void ActionNumber_t::update(toks_t toks, State_t<bool>& state,
    std::vector<Token_t>& tokens, char current_char)
{
    if (!state["any_active"] && Common::numeric_string(toks.first)) {
        this->m_expr = toks.first;
        state.set("number_active", true);
        state.set("any_active", true);
        toks.first = "";
        toks.second = "";
    } else if (state["number_active"] && ((std::isdigit(current_char) &&
        !IS_DELIM(current_char)) || current_char == '.'
                || current_char == 'f' || current_char == 'l' ||
                current_char == 'F' || current_char == 'L' ||
                current_char == 'u' || current_char == 'U')) {
        this->m_expr += toks.first;
        toks.first = "";
        toks.second = "";
    } else if (state["number_active"]) {
        state.set("number_active", false);
        state.set("any_active", false);
        tokens.push_back(make_token<std::string>(TokenType_t::TK_NUMBER,
                                                 this->m_expr));

        for (auto const& [key, val] : FOX_KEYWORDS) {
            if (key.length() == 1 && toks.first == key) {
                tokens.push_back(val);
                break;
            }
        }

        toks.first = "";
        toks.second = "";
    }
}
