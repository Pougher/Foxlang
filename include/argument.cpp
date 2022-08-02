#include "argument.hpp"

void Argument_t::parse(int argc, char** argv)
{
    bool matched = false;

    if (argc < 2) {
        Common::usage();
        std::exit(0);
    }

    for (auto& [key, val] : this->actions) {
        if (key == std::string(argv[1])) {
            if (!val->requirements(argc - 2)) {
                std::cerr << "Argument '" << argv[1] << "' received invalid arguments." << std::endl;
                std::cerr << "Usage: " << val->docstring() << std::endl;
                std::exit(0);
            }
            val->parse(argc - 2, argv + 2);
            matched = true;
        }
    }

    if (!matched) {
        std::cerr << "Unknown argument: '" << argv[1] << "'" << std::endl;
        std::exit(0);
    }
}

void Argument_t::add_action(std::string req, ArgumentAction_t* action)
{
    this->actions.insert( { req, action } );
}
