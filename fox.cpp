#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>

#include "include/file.hpp"
#include "include/lexer.hpp"
#include "include/parser.hpp"
#include "include/token.hpp"
#include "include/import_handler.hpp"
#include "include/common.hpp"
#include "include/scope.hpp"
#include "include/build_parser.hpp"

#include "include/argument.hpp"
#include "include/arg_build.hpp"
#include "include/arg_help.hpp"
#include "include/arg_new.hpp"
#include "include/arg_compile.hpp"

void build_file(const std::string& filename)
{
    std::string file = File::load_file(filename.c_str()) + "\n";
    file = ImportHandler::parse(file);
    Lexer_t lex(file);
    lex.lex();

    // parse the tokens
    Parser_t parser(lex.extract(), Common::c_filename(filename));
    parser.parse();
    parser.write();
}

void build_project()
{
    std::ifstream f("build.json");
    if (!f.good()) {
        std::cerr << "[FOX BUILD] Project build failed - directory has no project initialized" << std::endl;
        std::exit(1);
    }
    f.close();

    BuildParser_t build_parser("build.json");
    std::cout << "[FOX BUILD] Building project " << build_parser.get_project_name() << "..." << std::endl;
    std::string file = File::load_file("src/main.fox") + "\n";
    file = ImportHandler::parse(file);

    Lexer_t lex(file); lex.lex();
    Parser_t parser(lex.extract(), build_parser.get_output_dir() + "/" + Common::c_filename(build_parser.get_output_name()));
    parser.parse();
    parser.write();
    std::cout << "[FOX BUILD] Successfully built project " << build_parser.get_project_name() << std::endl;
}

void create_project(const std::string& name)
{
    BuildParser_t build_parser;
    build_parser.set_attributes(name, name, "build");
    build_parser.generate();
}

int main(int argc, char** argv)
{
    // init srand
    srand(time(NULL));

    Argument_t argparser;
    argparser.add_action("help", new ArgumentActionHelp_t());
    argparser.add_action("build", new ArgumentActionBuild_t());
    argparser.add_action("new", new ArgumentActionNew_t());
    argparser.add_action("compile", new ArgumentActionCompile_t());

    argparser.parse(argc, argv);
    return 0;
}
