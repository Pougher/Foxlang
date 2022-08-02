#pragma once

#include <string>
#include <iostream>
#include <map>

#include "common.hpp"
#include "argument_action.hpp"

/* Argument_t class to parse arguments passed through argv */
class Argument_t {
public:
    /* parses the argument passed to the program */
    void parse(int argc, char** argv);
    /* adds an argument action to the map */
    void add_action(std::string req, ArgumentAction_t* action);
private:
    std::map<std::string, ArgumentAction_t*> actions;
};
