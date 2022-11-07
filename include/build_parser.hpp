#pragma once

#include "json.hpp"
#include "file.hpp"
#include "error.hpp"
#include "standard_library.hpp"

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

const std::vector<const char*> STANDARD_FILES {
    "standard/fenv.fox",
    "standard/float.fox",
    "standard/inttypes.fox",
    "standard/signal.fox",
    "standard/stddef.fox",
    "standard/errno.fox",
    "standard/wchar.fox",
    "standard/uchar.fox",
    "standard/stdbool.fox",
    "standard/time.fox",
    "standard/iso646.fox",
    "standard/stdalign.fox",
    "standard/locale.fox",
    "standard/stdarg.fox",
    "standard/assert.fox",
    "standard/math.fox",
    "standard/limits.fox",
    "standard/setjmp.fox",
    "standard/stdnoreturn.fox",
    "standard/ctype.fox",
    "standard/stdint.fox",
    "standard/string.fox",
    "standard/wctype.fox",
    "standard/stdio.fox",
    "standard/stdlib.fox"
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
    /* converts JSON list to std::vector<std::string> */
    std::vector<std::string> to_vector(nlohmann::json& json);

    /* getter methods */
    std::string& get_project_name();
    std::string& get_output_name();
    std::string& get_output_dir();
    std::vector<std::string>& get_compile_options();
    std::string& get_compile_command();
    std::string& get_output_type();
    bool get_run_command();
    bool get_no_std();
private:
    /* project attributes */
    std::string project_name;
    std::string output_name;
    std::string output_dir;

    /* compilation attributes */
    bool run_compile_command;
    bool no_std;
    std::vector<std::string> compile_options;
    std::string compile_command;
    std::string output_type;
};
