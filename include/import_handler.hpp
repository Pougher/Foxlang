#include <string>
#include <vector>
#include <algorithm>

#include "common.hpp"
#include "error.hpp"
#include "file.hpp"

/* parser for imports, allowing for files to include other files */
namespace ImportHandler {
    const std::string parse(std::string& str);
    const std::string recursive_parse(std::string& str, std::vector<std::string>& already_included);
}