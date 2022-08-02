#pragma once

#include <iostream>
#include <fstream>

#include "argument_action.hpp"
#include "lexer.hpp"
#include "parser.hpp"
#include "import_handler.hpp"
#include "file.hpp"


class ArgumentActionCompile_t : public ArgumentAction_t {
    void parse(int argc, char** argv) override
    {
        (void) argc;
        std::string file = File::load_file(argv[0]) + "\n";
        file = ImportHandler::parse(file);
        Lexer_t lex(file);
        lex.lex();

        // parse the tokens
        Parser_t parser(lex.extract(), Common::c_filename(argv[0]));
        parser.parse();
        parser.write();
    }

    bool requirements(int argc) override
    {
        if (argc == 1) return true;
        return false;
    }

    std::string docstring() override
    {
        return "fox [compile] <name>\n    compile: emits a C program based off of the input file";
    }
};
