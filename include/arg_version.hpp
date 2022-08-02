#pragma once

#include "argument_action.hpp"
#include "common.hpp"

class ArgumentActionVersion_t : public ArgumentAction_t {
public:
    void parse(int argc, char** argv) override
    {
        (void) argc;
        (void) argv;
        std::cout << Common::version() << std::endl;
    }

    bool requirements(int argc) override
    {
        if (argc == 0) return true;
        return false;
    }

    std::string docstring() override
    {
        return "fox [version]\n    version: displays the executable version";
    }
};
