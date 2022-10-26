#include "lexer.hpp"

Lexer_t::Lexer_t(std::string& file)
{
    // initialize all data in lexer
    this->m_file = file;
    this->m_toks = "";
    this->m_ftoks = "";

    // init lexer m_actions
    this->m_actions.insert(this->m_actions.end(), {
            new ActionString_t(),
            new ActionNumber_t()
        }
    );
}

void Lexer_t::keyword(const std::string& kw, Token_t tk, char n)
{
    /* since all keywords end in a delimiter, check if the next character
       is a delimiter. Then check if the `this->toks` variable is the value
       we are looking for, and if it is then append the token. */

    if (this->m_toks == kw && !this->m_state["any_active"]) {
        if (kw.length() == 1) {
            this->m_tokens.push_back(tk);
            this->m_toks = "";
            this->m_ftoks = "";
        }
        else if (IS_DELIM(n)) {
            this->m_tokens.push_back(tk);
            this->m_toks = "";
            this->m_ftoks = "";
        }
    }
}

void Lexer_t::type_veccheck(std::set<std::string>& types, char n)
{
    /* using std::set instead of std::vector as std::set has a find
     * method which has a time complexity of O(log n) in comparison
     * to std::vector with a time complexity of O(n) */

    // remove asterisks
    bool found_asterisk = false;
    long asterisks = 0;
    std::string type_name = "";

    for (uint64_t i = 0; i < this->m_toks.size(); i++) {
        if (this->m_toks[i] == '*') { found_asterisk = true; asterisks ++; }
        if (!found_asterisk) type_name += this->m_toks[i];
    }

    if ((types.find(type_name) != types.end()) && IS_DELIM(n) && n != '*') {

        Token_t new_token(TokenType_t::TK_TYPE);
        new_token.get_data().push_back(type_name);
        new_token.get_data().push_back(asterisks);

        this->m_tokens.push_back(new_token);
        this->m_toks = "";
        this->m_ftoks = "";
    }
}

char Lexer_t::remove_delimiter(std::string& s)
{
    if (IS_DELIM(s[s.length() - 1])) {
        s = s.substr(0, s.length() - 1);
        return s[s.length() - 1];
    }
    return '\0';
}

void Lexer_t::lex()
{
    uint64_t line = 0;
    bool comment = false;

    // convert the file into lines

    std::vector<std::string> lines = Common::split(this->m_file, '\n');

    for (unsigned long i = 0; i < this->m_file.length(); i++) {
        if (comment && this->m_file[i] == '\n') {
            comment = false;
            continue;
        }
        if (comment) continue;

        if (i + 1 < this->m_file.size()) {
            if (this->m_file[i] == '/' && this->m_file[i + 1] == '/') {
                comment = true;
                i++;
                continue;
            }
        }

        if (this->m_file[i] != '\n') this->m_ftoks += this->m_file[i];
        if (!IS_WHITESPACE(this->m_file[i])) this->m_toks += this->m_file[i];

        if (i + 1 < this->m_file.length()) {
            this->type_veccheck(FOX_TYPES, this->m_file[i + 1]);
        }
        this->keyword_mapcheck(FOX_KEYWORDS, this->m_file[i]);

        for (auto& action : this->m_actions) {
            action->update(
                    construct_toks_t(this->m_toks, this->m_ftoks),
                    this->m_state,
                    this->m_tokens,
                    this->m_file[i]
            );
        }

        if (IS_DELIM(this->m_file[i])) {
            if (this->m_toks != "" && !this->m_state["any_active"] && \
                FOX_TYPES.find(this->remove_asterisks(this->m_toks)) ==
                FOX_TYPES.end()) {
                std::string tk_copy = this->m_toks;
                (void) this->remove_delimiter(tk_copy);
                char delim = this->m_toks[this->m_toks.length() - 1];
                if (this->m_tokens.size() > 0) {
                    if (this->m_tokens[this->m_tokens.size() - 1].get_type()
                        == TK_STRUCT ||
                        this->m_tokens[this->m_tokens.size() - 1].get_type()
                        == TK_UNION ||
                        this->m_tokens[this->m_tokens.size() - 1].get_type()
                        == TK_TYPE_EXT) {
                        FOX_TYPES.insert(tk_copy);
                    }
                }
                this->m_tokens.push_back(make_token<std::string>(
                        TokenType_t::TK_IDENTIFIER, tk_copy));
                this->m_ftoks = this->m_file[i];
                if (IS_DELIM(delim)) {
                    this->m_toks = delim;
                    this->m_ftoks = delim;
                }  else {
                    this->m_toks = "";
                    this->m_ftoks = "";
                }
                // run analysis on the leftover character
                this->keyword_mapcheck(FOX_KEYWORDS, this->m_file[i]);
            }
        }

        if (this->m_file[i] == '\n') {
            line ++; // increment the line counter
            this->m_tokens.push_back(Token_t(TokenType_t::TK_NEWLINE));
        }
    }
}

void Lexer_t::keyword_mapcheck(const std::map<const std::string, Token_t>& kw,
                               char n)
{
    for (auto const& [key, val] : kw) {
        this->keyword(key, val, n);
    }
}

Lexer_t::~Lexer_t()
{
    // free all lexer actions
    while (this->m_actions.size() > 0) {
        auto ptr = this->m_actions.back();
        this->m_actions.pop_back();
        delete ptr;
    }
}

std::vector<Token_t>& Lexer_t::extract() { return this->m_tokens; }

std::string Lexer_t::remove_asterisks(const std::string& str)
{
    std::string ret = "";
    bool asterisks = false;

    for (auto c : str) {
        if (c == '*') asterisks = true;
        if (!asterisks) ret += c;
    }

    return ret;
}
