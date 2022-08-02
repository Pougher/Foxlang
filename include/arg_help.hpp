#pragma once

#include "argument_action.hpp"
#include "common.hpp"

class ArgumentActionHelp_t : public ArgumentAction_t {
public:
    void parse(int argc, char** argv) override
    {
        (void) argc;
        (void) argv;
        Common::usage();
    }

    bool requirements(int argc) override
    {
        if (argc == 0) return true;
        return false;
    }

    std::string docstring() override
    {
        return "fox [help]\n    help: outputs the helpstring for the program";
    }
};
