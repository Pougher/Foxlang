#pragma once

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <cstdint>
#include <cstdlib>

/* Macro for checking if the current token in a delimiter or not */
#define IS_DELIM(x) (x == ',' || x == '.' || x == '*' || x == '+' ||   \
                     x == '/' || x == '-' || x == ' ' || x == '\n' ||  \
                     x == '[' || x == ']' || x == '{' || x == '}' ||   \
                     x == '%' || x == '\r' || x == '\t' || x == '<' || \
                     x == ';' || x == '>' || x == ':' || x == '^' ||   \
                     x == '&' || x == '~' || x == '(' || x == ')' ||   \
                     x == '=' || x == '\''|| x == '"' )

/* Macro for checking if the current token is a whitespace character or not */
#define IS_WHITESPACE(x) (x == '\t' || x == '\r' || x == '\n' || x == ' ')

/* global variable for the number of brace scopes generated */
static unsigned long g_common_brace_count = 0;

/* list of all alphanumeric characters */
static std::array<char, 62> COMMON_ALPHANUMERICS {
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
    'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z', '0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9'
};

/* use of a namespace in order to make sure function name clashing
 * doesn't occur */
namespace Common
{
    /* splits a string into an std::vector of strings based off of
     * a delimiter. When the delimiter is encountered, the sting is
     * split and a new element is appended to the std::vector. */
    std::vector<std::string> split(std::string& data, char delim);

    /* removes all of the preceeding whitespace from a string. */
    std::string remove_preceeding_whitespace(std::string& data);

    /* counts the number of preceeding whitespace characters in a
     * string */
    uint64_t count_preceeding_whitespacce(std::string& data);

    /* gets the intersection between two strings and returns the
     * index */
    int64_t string_intersection(std::string str1, std::string str2);

    /* is a better version of the cassert function. Checks if `cond`
     * is true, and if it is not, then the function tests if `fatal`
     * is also true. If it is, the program exits with the error
     * message. Otherwise, just the error message is shown. */
    void common_assert(bool cond, std::string& err, bool fatal);

    /* Checks if a string is numeric or not */
    bool numeric_string(const std::string& s);

    /* removes the old file ending (if it has one) and appends `.c`
     * on the end */
    std::string c_filename(const std::string& old_filename);
    /* remove the old filename and add the new filename parameter */
    std::string replace_extension(const std::string& old_filename,
        const std::string& extension);

    /* function to return the default code for the C program*/
    const std::string default_c(bool nostd = false);

    /* function to generate a generic brace scope name */
    const std::string brace_scope_name(std::vector<std::string>& alr_defined);

    /* produces garbage characters */
    const std::string garbage(unsigned int mangle_len);

    /* replace any appearances of `from` in `str` with`to` */
    void replace(std::string& str, const std::string& from,
                 const std::string& to);

    /* prints the usage of the executable */
    void usage();

    /* outputs the version of the executable */
    const std::string version();

    /* gets the file extension of the filetype */
    const std::string file_extension(const std::string& ft);
}
