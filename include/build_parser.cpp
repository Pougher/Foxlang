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
        file_json["project"].contains("directory"))) {
        std::cerr << JSON_ERROR << ":\n" << "    build.json must contain `project` object with the" <<
            " following attributes:\n" <<
            "{\n    \"project\": {\n        \"output\": <value>,\n        \"name\": <value>,\n        \"directory\": <value>\n    }\n}"
            << std::endl;
        std::exit(1);
    }

    this->project_name = this->strip_quotes(file_json["project"]["name"]);
    this->output_name  = this->strip_quotes(file_json["project"]["output"]);
    this->output_dir   = this->strip_quotes(file_json["project"]["directory"]);
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
    for (unsigned int i = 0; i < PROJECT_DEFAULT_FILES.size(); i++) {
        File::write_file(PROJECT_DEFAULT_FILES[i], PROJECT_DEFAULT_FILE_CONTENTS[i]);
    }

    // write the project json
    File::write_file("build.json", this->generate_build_json());
}

const std::string BuildParser_t::generate_build_json()
{
    const std::string json = "{\n"
                             "    \"project\": {\n"
                             "        \"name\": \"" + this->project_name + "\",\n"
                             "        \"output\": \"" + this->output_name + "\",\n"
                             "        \"directory\": \"" + this->output_dir + "\"\n"
                             "    }\n"
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

std::string& BuildParser_t::get_project_name() { return this->project_name; }
std::string& BuildParser_t::get_output_name() { return this->output_name; }
std::string& BuildParser_t::get_output_dir() { return this->output_dir; }
