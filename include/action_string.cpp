#include "action_string.hpp"

ActionString_t::~ActionString_t() {}

ActionString_t::ActionString_t()
{
    // init.
    this->m_expr = "";
    this->m_escape = false;
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
    } else if (state["string_active"] && (current_char != '"' ||
        this->m_escape)) {
        if (!this->m_escape) {
            if (current_char == '\\') {
                this->m_escape = true;
            }
            this->m_expr += current_char;
        } else {
            switch (current_char) {
                case '"': { this->m_expr += "\""; break; }
                case 'n': { this->m_expr += "\\n"; break; }
                case 't': { this->m_expr += "\\t"; break; }
                case 'a': { this->m_expr += "\\a"; break; }
                case 'x': { this->m_expr += "\\x"; break; }
                case 'b': { this->m_expr += "\\b"; break; }
                case 'u': { this->m_expr += "\\u"; break; }
                case 'U': { this->m_expr += "\\U"; break; }
                case 'r': { this->m_expr += "\\r"; break; }
                default: {
                    if (std::isdigit(current_char)) {
                        this->m_expr += current_char;
                    } else {
                        std::cout << "Invalid escape sequence: " << current_char
                            << std::endl;
                        std::exit(1);
                    }
                    break;
                }
            }
            this->m_escape = false;
        }
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
