#pragma once

#include <fstream>
#include <iostream>
#include <string>
#include <chrono>

#include "argument_action.hpp"
#include "common.hpp"
#include "build_parser.hpp"
#include "import_handler.hpp"
#include "parser.hpp"
#include "lexer.hpp"
#include "command_exec.hpp"

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

        // time the codegen process
        auto start = std::chrono::high_resolution_clock::now();

        Lexer_t lex(file); lex.lex();
        Parser_t parser(lex.extract(), build_parser.get_output_dir() + "/" + \
            Common::c_filename(build_parser.get_output_name()));

        parser.set_language(Common::file_extension(
            build_parser.get_output_type()));
        parser.set_default_c(Common::default_c(build_parser.get_no_std()));
        parser.parse();
        parser.write();

        auto end = std::chrono::high_resolution_clock::now();
        std::cout << "[FOX BUILD] Transpilation took " <<
            (std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
            .count() / 1000.0) << "s" << std::endl;

        std::cout << "[FOX BUILD] Successfully built project " << \
            build_parser.get_project_name() << std::endl;

        // compilation step
        std::cout << "[FOX BUILD] Running compile command..." << std::endl;

        std::string command = build_parser.get_compile_command() +         \
                              " build/" + build_parser.get_output_name() + \
                              Common::file_extension(
                                  build_parser.get_output_type()) +        \
                              " -o build/" +                               \
                              build_parser.get_project_name();

        for (std::string& opt : build_parser.get_compile_options()) {
            command += " " + opt;
        }

        std::cout << "[FOX BUILD] Execute: " << command << std::endl;

        // time the compile command process
        start = std::chrono::high_resolution_clock::now();

        int result = CommandExec::execute(command) / 256;
        if (result == 0) {
            std::cout << "[FOX BUILD] Compiled project successfully"
                << std::endl;
        } else {
            std::cout << "[FOX BUILD] Compilation did not complete (exit " <<
                "code " << result << ")" << std::endl;
            std::exit(-1);
        }
        end = std::chrono::high_resolution_clock::now();
        std::cout << "[FOX BUILD] Compile command took " <<
            (std::chrono::duration_cast<std::chrono::milliseconds>(end - start)
            .count() / 1000.0) << "s" << std::endl;
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
