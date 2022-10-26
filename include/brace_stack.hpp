#pragma once

#include <vector>

/* NONE used for braces. Namespace braces are used to know
 * when a namespace is closed */
enum Brace_t {
    NONE,
    NAMESPACE,
    STRUCTURE
};

/* struct for the various types of brace, such as curly braces,
 * (`{` and `}`), square braces, (`[` and `]`), and regular
 * parenthesis (`(` and `)`). */
struct BraceStack_t {
    std::vector<Brace_t> curly_brace;
    std::vector<Brace_t> square_brace;
    std::vector<Brace_t> brace;

    Brace_t curly_brace_top()
    {
        if (this->curly_brace.size() == 0) return Brace_t::NONE;
        return this->curly_brace[this->curly_brace.size() - 1];
    }

    Brace_t square_brace_top()
    {
        if (this->square_brace.size() == 0) return Brace_t::NONE;
        return this->square_brace[this->square_brace.size() - 1];
    }

    Brace_t brace_top()
    {
        if (this->brace.size() == 0) return Brace_t::NONE;
        return this->brace[this->brace.size() - 1];
    }
};
