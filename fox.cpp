#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

#include "include/argument.hpp"
#include "include/arg_build.hpp"
#include "include/arg_help.hpp"
#include "include/arg_new.hpp"
#include "include/arg_compile.hpp"
#include "include/arg_version.hpp"

int main(int argc, char** argv)
{
    // init srand
    srand(time(NULL));

    Argument_t argparser;
    argparser.add_action("help", new ArgumentActionHelp_t());
    argparser.add_action("build", new ArgumentActionBuild_t());
    argparser.add_action("new", new ArgumentActionNew_t());
    argparser.add_action("compile", new ArgumentActionCompile_t());
    argparser.add_action("version", new ArgumentActionVersion_t());

    argparser.parse(argc, argv);
    return 0;
}
