#include "error.hpp"

void Error::SyntaxError(
        const std::string& msg,
        uint64_t line,
        std::string& line_str,
        std::string toks,
        bool fatal)
{
    // remove preceeding whitespace because it looks better
    std::string fixed_str = Common::remove_preceeding_whitespace(line_str);

    if (toks != "") {
        long int intersect = Common::string_intersection(line_str, toks);
        intersect = intersect - Common::count_preceeding_whitespacce(line_str);

        std::cerr << "Syntax Error on line " << line << ":\n    "
            << line_str << std::endl;
        for (long int i = 0; i < intersect + 4; i++) { std::cout << "~"; }
        std::cerr << "^\n";
        std::cerr << msg << std::endl;
    }

    // if the error is considered fatal by the program,
    // exit.
    if (fatal) {
        std::exit(1);
    }
}

void Error::GenericError_nl(
        const std::string& msg,
        const std::string& err,
        uint64_t line,
        bool fatal)
{
    std::cerr << err << " on line " << line << ":\n    " << \
        msg << std::endl;

    if (fatal) std::exit(1);
}
