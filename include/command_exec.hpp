#pragma once

#include <unistd.h>
#include <string>
#include <vector>
#include <iostream>
#include <cstdio>

/* safely execute commands from within the program */
namespace CommandExec {
    /* execute a command using `arguments` as the arguments for the command */
    int execute(const std::string& command);
    /* make sure that nobody is trying to run an exploit */
    void check_arguments(const std::string& arguments);
}
