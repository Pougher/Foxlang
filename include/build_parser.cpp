#include "build_parser.hpp"

using Json_t = nlohmann::json;

BuildParser_t::BuildParser_t(const char* filename)
{
    std::string file = File::load_file(filename);
    Json_t file_json;

    try {
        file_json = Json_t::parse(file);
    } catch (Json_t::exception& e) {
        std::cerr << JSON_ERROR << ":\n\t" << e.what() << std::endl;
        std::exit(1);
    }

    if (!(file_json.contains("project") &&
        file_json["project"].contains("name") &&
        file_json["project"].contains("output") &&
        file_json["project"].contains("directory") &&
        file_json.contains("run_compile_command") &&
        file_json.contains("compile_command") &&
        file_json.contains("compile_options"))) {
        std::cerr << JSON_ERROR << ":\n" << "    build.json must contain "
            "`project` object with the" <<
            " following attributes:\n" <<
            "{\n    \"project\": {\n        \"output\": <value>,\n        "
            "\"name\": <value>,\n        \"directory\": <value>\n    },\n"
            "    \"run_compile_command\": <bool>,\n    \"compile_command\""
            ": <value>,\n    \"compile_options\": []\n"
            "}"
            << std::endl;
        std::exit(1);
    }

    this->project_name = this->strip_quotes(file_json["project"]["name"]);
    this->output_name  = this->strip_quotes(file_json["project"]["output"]);
    this->output_dir   = this->strip_quotes(file_json["project"]["directory"]);

    // compile options
    this->compile_options = this->to_vector(file_json["compile_options"]);
    this->run_compile_command = file_json["run_compile_command"];
    this->compile_command = this->strip_quotes(file_json["compile_command"]);

    if (file_json.contains("output_type")) {
        const std::string output_type_before = file_json["output_type"];
        std::string output_type = "";

        for (char c : output_type_before) {
            output_type += std::toupper(c);
        }

        if (!(output_type == "C" || output_type == "C++" ||
              output_type == "CPP" || output_type == "CXX" ||
              output_type == "CC")) {
            // invalid output type
            std::cerr << "Error: Invalid output type '" << output_type_before <<
                "'" << std::endl;
            std::exit(-1);
        }

        this->output_type = output_type;
    } else {
        this->output_type = "C"; // default
    }

    if (file_json["project"].contains("no_std")) {
        this->no_std = file_json["project"]["no_std"];
    }
}

std::string BuildParser_t::strip_quotes(std::string str)
{
    str.erase(std::remove(str.begin(), str.end(), '\"' ), str.end());
    return str;
}

void BuildParser_t::generate()
{
    for (auto name : PROJECT_DIR_NAMES) {
        std::filesystem::create_directories(name);
    }

    for (unsigned int i = 0; i < NUM_STANDARD_FILES; i++) {
        File::write_file(STANDARD_FILES[i], STANDARD_LIB_FILES[i]);
    }

    for (unsigned int i = 0; i < PROJECT_DEFAULT_FILES.size(); i++) {
        File::write_file(PROJECT_DEFAULT_FILES[i],
            PROJECT_DEFAULT_FILE_CONTENTS[i]);
    }

    // write the project json
    File::write_file("build.json", this->generate_build_json());
}

const std::string BuildParser_t::generate_build_json()
{
    const std::string json = "{\n"
                             "    \"project\": {\n"
                             "        \"name\": \"" + this->project_name + \
                                "\",\n"
                             "        \"output\": \"" + this->output_name + \
                                "\",\n"
                             "        \"directory\": \"" + this->output_dir + \
                             "\"\n"
                             "    },\n"
                             "    \"run_compile_command\": true,\n"
                             "    \"compile_command\": \"clang\",\n"
                             "    \"compile_options\": [ \"-O3\" ]\n"
                             "}\n";
    return json;
}

void BuildParser_t::set_attributes(const std::string& name,
        const std::string& output,
        const std::string& out_dir)
{
    this->project_name = name;
    this->output_name = output;
    this->output_dir = out_dir;
}

std::vector<std::string> BuildParser_t::to_vector(Json_t& json)
{
    std::vector<std::string> strings;
    for (unsigned int i = 0; i < json.size(); i++) {
        strings.push_back(this->strip_quotes(json[i]));
    }

    return strings;
}

std::string& BuildParser_t::get_project_name() { return this->project_name; }
std::string& BuildParser_t::get_output_name() { return this->output_name; }
std::string& BuildParser_t::get_output_dir() { return this->output_dir; }
std::string& BuildParser_t::get_output_type() { return this->output_type; }
std::vector<std::string>& BuildParser_t::get_compile_options()
{ return this->compile_options; }
bool BuildParser_t::get_run_command() { return this->run_compile_command; }
std::string& BuildParser_t::get_compile_command()
{ return this->compile_command; }
bool BuildParser_t::get_no_std() { return this->no_std; }
