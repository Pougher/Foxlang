#pragma once

#include "json.hpp"
#include "file.hpp"
#include "error.hpp"

#include <string>
#include <filesystem>
#include <vector>

const std::vector<const char*> PROJECT_DIR_NAMES {
    "src",
    "build",
    "standard"
};

const std::vector<const char*> PROJECT_DEFAULT_FILES {
    "src/main.fox"
};

const std::vector<const char*> PROJECT_DEFAULT_FILE_CONTENTS {
    "fn main() -> i32 {\n"
    "    return 0;\n"
    "}\n"
};

/* parser to read build.json and construct a project
 * folder with the correct configuration */
class BuildParser_t {
public:
    /* reads the file and generates basic information about the build */
    BuildParser_t(const char* filename);
    /* override in case a new project is being created */
    BuildParser_t() {};
    /* remove quotes from a string */
    std::string strip_quotes(std::string str);
    /* generates a build.json for a project */
    const std::string generate_build_json();
    /* generates the structure of a project */
    void generate();
    /* sets the attributes for the project */
    void set_attributes(const std::string& name,
            const std::string& output,
            const std::string& out_dir);
    std::string& get_project_name();
    std::string& get_output_name();
    std::string& get_output_dir();
private:
    std::string project_name;
    std::string output_name;
    std::string output_dir;
};
