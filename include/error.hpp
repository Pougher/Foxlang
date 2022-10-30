#pragma once
#include <iostream>
#include <string>

#include "common.hpp"

#define ERROR_EOF       "EOFError"
#define ERROR_SYNTAX    "SyntaxError"
#define BRACE_ERROR     "BraceError"
#define REDEF_ERROR     "RedefinitionError"
#define NAMESPACE_ERROR "NamespaceError"
#define IMPORT_ERROR    "ImportError"
#define IO_ERROR        "IOError"
#define CHAR_ERROR      "CharError"
#define JSON_ERROR      "JSONError"

/* Namespace to contain all error functions */
namespace Error
{
    /* Function to display a formatted syntax error */
    void SyntaxError(
            const std::string& msg,
            uint64_t line,
            std::string& line_str,
            std::string toks = "",
            bool fatal = true
    );

    /* function to display a formatted generic error without a line message */
    void GenericError_nl(
            const std::string& msg,
            const std::string& err,
            uint64_t line,
            bool fatal = true
    );
}
