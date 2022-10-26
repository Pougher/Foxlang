#pragma once

#include <fstream>
#include <iostream>
#include <string>

#include "argument_action.hpp"
#include "common.hpp"
#include "build_parser.hpp"
#include "import_handler.hpp"
#include "parser.hpp"
#include "lexer.hpp"

class ArgumentActionBuild_t : public ArgumentAction_t {
public:
    void parse(int argc, char** argv) override
    {
        (void) argc;
        (void) argv;

        std::ifstream f("build.json");
        if (!f.good()) {
            std::cerr << "[FOX BUILD] Project build failed - directory has no "
            "project initialized" << std::endl;
            std::exit(1);
        }
        f.close();

        BuildParser_t build_parser("build.json");
        std::cout << "[FOX BUILD] Building project " << \
            build_parser.get_project_name() << "..." << std::endl;
        std::string file = File::load_file("src/main.fox") + "\n";
        file = ImportHandler::parse(file);

        Lexer_t lex(file); lex.lex();
        Parser_t parser(lex.extract(), build_parser.get_output_dir() + "/" + \
            Common::c_filename(build_parser.get_output_name()));
        parser.parse();
        parser.write();
        std::cout << "[FOX BUILD] Successfully built project " << \
            build_parser.get_project_name() << std::endl;
    }

    bool requirements(int argc) override
    {
        if (argc == 0) return true;
        return false;
    }

    std::string docstring() override
    {
        return "fox [build]\n    build: compiles a fox project within a "
            "directory";
    }
};
