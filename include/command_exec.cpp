#include "command_exec.hpp"

void CommandExec::check_arguments(
    const std::string& arguments)
{
    for (char c : arguments) {
        if (c == '|' || c == '&' || c == ';' || c == ':') {
            std::cerr << "Error: Illegal characters found in process string"
                << std::endl;
            std::exit(-1);
        }
    }
}

int CommandExec::execute(const std::string& command)
{
    // check if there is any funny business going on
    CommandExec::check_arguments(command);

    char buffer[128];
    std::string result = "";
    FILE* pipe = popen(command.c_str(), "r");

    if (!pipe) {
        std::cerr << "Failed to create child process `" << command <<
            "` [FATAL] Exiting";
        std::exit(-1);
    }
    try {
        while (fgets(buffer, sizeof(buffer), pipe) != NULL) {
            result += buffer;
        }
    } catch (...) {
        pclose(pipe);
        std::cerr << "Failed to execute command `" << command << "`" <<
            std::endl;
        std::exit(-1);
    }

    return pclose(pipe);
}
