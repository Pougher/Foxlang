#pragma once

#include "build_parser.hpp"

class ArgumentActionNew_t : public ArgumentAction_t {
public:
    void parse(int argc, char** argv) override
    {
        (void) argc;

        BuildParser_t build_parser;
        build_parser.set_attributes(argv[0], argv[0], "build");
        build_parser.generate();
    }

    bool requirements(int argc) override
    {
        if (argc == 1) return true;
        return false;
    }

    std::string docstring() override
    {
        return "fox [new] <name>\n    new: creates a fox project in the current working directory";
    }
};
