#include "import_handler.hpp"

const std::string ImportHandler::parse(std::string& str)
{
    std::vector<std::string> already_included;
    std::string result = ImportHandler::recursive_parse(str, already_included);

    return result;
}

const std::string ImportHandler::recursive_parse(std::string& str,
    std::vector<std::string>& already_included)
{
    std::string toks = "";
    std::string import_string = "";
    std::string back_buffer = "";
    std::string completed_file = "";
    bool import_active = false;
    long line = 1;
    unsigned char skip = 0;

    for (char c : str) {
        if (skip) {
            skip --;
            continue;
        }
        if (c != ' ' && c != '\t' && c != '\n') toks += c;
        if (c == '\n') line ++;

        if (toks == "import") {
            import_active = true;
            toks = "";
            skip = 1;
            back_buffer = "";
            continue;
        } else if (import_active && c != '\n') {
            if (c == ' ' || c == '\t') {
                // there should not be any whitespace characters in an import
                Error::GenericError_nl(
                        "Whitespace should not be present in an import"
                        "statement",
                        IMPORT_ERROR,
                        line
                );
            }
            import_string += c;
            toks = "";
        } else if (import_active) {
            if (import_string == "") {
                Error::GenericError_nl(
                        "Import statement requires a filename",
                        IMPORT_ERROR,
                        line
                );
            }

            if (!std::filesystem::exists(import_string)) {
                Error::GenericError_nl(
                        std::string("Could not find file for import: '") + \
                        import_string + "'",
                        IO_ERROR,
                        line
                );
            }

            if (std::find(already_included.begin(), already_included.end(),
                import_string) != already_included.end()) {
                import_string = "";
                import_active = false;
                continue;
            }

            already_included.push_back(import_string);
            std::string loaded_file = File::load_file(import_string.c_str());

            completed_file += "\n" + ImportHandler::recursive_parse(loaded_file,
                already_included) + "\n";
            import_string = "";
            import_active = false;
        }

        if (c == '\n') {
            toks = "";
            completed_file += back_buffer;
            back_buffer = "";
        }
        if (!import_active) back_buffer += c;
    }
    return completed_file; // DEBUG:
}
