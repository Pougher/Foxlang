#include "common.hpp"

std::vector<std::string> Common::split(std::string& data, char delim)
{
    std::vector<std::string> split_data;
    std::string curr = "";

    for (char i : data) {
        if (i == delim) {
            split_data.push_back(curr);
            curr = "";
        } else {
            curr += i;
        }
    }
    return split_data;
}


std::string Common::remove_preceeding_whitespace(std::string& data)
{
    bool encountered = false;
    std::string constructed = "";

    for (char i : data) {
        if (!IS_WHITESPACE(i)) encountered = true;
        if (encountered) {
            constructed += i;
        }
    }

    return constructed;
}

uint64_t Common::count_preceeding_whitespacce(std::string& data)
{
    uint64_t count = 0;
    while (IS_WHITESPACE(data[count])) count ++;
    return count;
}

int64_t Common::string_intersection(std::string str1, std::string str2)
{
    int64_t idx = -1;
    for (uint64_t i = 0; i < str1.length(); i++) {
        if (str2 == str1.substr(i, str1.length())) {
            idx = i;
            break;
        }
    }

    return idx;
}

void Common::common_assert(bool cond, std::string& err, bool fatal = true)
{
    // if the condition is false, exit with an error.
    if (cond) {
        std::cout << "Assertation failed: " << err << std::endl;
        if (fatal) std::exit(1);
    }
}

bool Common::numeric_string(const std::string& s)
{
    return !s.empty() && std::find_if(s.begin(),
            s.end(), [](unsigned char c) { return !std::isdigit(c); }) ==
                s.end();
}

std::string Common::c_filename(const std::string& old_filename)
{
    std::string file_name = "";
    unsigned int num_dots = 0;
    unsigned int cur_dots = 0;

    for (auto c : old_filename) { if (c == '.') num_dots++; }

    for (auto c : old_filename) {
        if (c == '.') {
            if (cur_dots == (num_dots - 1)) break;
            cur_dots ++;
        }
        file_name += c;
    }

    return file_name + ".c";
}

std::string Common::replace_extension(const std::string& old_filename,
    const std::string& extension)
{
    std::string file_name = "";
    unsigned int num_dots = 0;
    unsigned int cur_dots = 0;

    for (auto c : old_filename) { if (c == '.') num_dots++; }

    for (auto c : old_filename) {
        if (c == '.') {
            if (cur_dots == (num_dots - 1)) break;
            cur_dots ++;
        }
        file_name += c;
    }

    return file_name + extension;

}

const std::string Common::default_c(bool nostd)
{
    if (nostd) {
        // NOTE: Types are not guarunteed to be the exact size
        // shown in nostd mode.
        return "typedef unsigned long long u64;\n"
               "typedef unsigned int u32;\n"
               "typedef unsigned short u16;\n"
               "typedef unsigned char u8;\n"
               "typedef signed long long i64;\n"
               "typedef signed int i32;\n"
               "typedef signed short i16;\n"
               "typedef signed char i8;\n"
               "typedef float f32;\n"
               "typedef double f64;\n\n";
    }
    return "#include <stdint.h>\n#include <stdio.h>\n\n"
           "typedef uint64_t u64;\n"
           "typedef uint32_t u32;\n"
           "typedef uint16_t u16;\n"
           "typedef uint8_t u8;\n"
           "typedef int64_t i64;\n"
           "typedef int32_t i32;\n"
           "typedef int16_t i16;\n"
           "typedef int8_t i8;\n"
           "typedef float f32;\n"
           "typedef double f64;\n\n";
}

const std::string Common::brace_scope_name(
    std::vector<std::string>& alr_defined)
{
    std::string name = "brace_scope_" + std::to_string(g_common_brace_count);
    while (std::find(alr_defined.begin(), alr_defined.end(), name) !=
           alr_defined.end()) {
        g_common_brace_count ++;
        name = "brace_scope_overflow_" + std::to_string(g_common_brace_count);
    }
    g_common_brace_count ++;
    return name;
}

const std::string Common::garbage(unsigned int mangle_len)
{
    std::string mangle_str = "";
    for (unsigned int i = 0; i < mangle_len; i++) {
        mangle_str += COMMON_ALPHANUMERICS[
            rand() % COMMON_ALPHANUMERICS.size()];
    }

    return mangle_str;
}

void Common::replace(std::string& str, const std::string& from,
    const std::string& to)
{
    if (from.empty()) return;
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length(); // In case 'to' contains 'from', like
                                  // replacing 'x' with 'yx'
    }
}

void Common::usage()
{
    std::cout << "usage: ./fox [build] [new] [compile] [help] <name>\n" <<
                 "       Emits C programs based off of a fox program\n" <<
                 "\nOptions:\n\n" <<
                 "    build:   compiles a fox project within a directory\n"  <<
                 "    new:     creates a new fox project in the current "
                 "working directory\n" <<
                 "    compile: emits a C program based off of the input file\n"
                 << "    help:    outputs the helpstring for the program\n" <<
                 "    version: displays the executable version\n" <<
                std::endl;
}

const std::string Common::version()
{
    return "Fox C transpiler 1.0.2a4";
}

const std::string Common::file_extension(const std::string& ft)
{
    if (ft == "C") return ".c";
    if (ft == "CPP") return ".cpp";
    if (ft == "C++") return ".cpp";
    if (ft == "CXX") return ".cpp";
    if (ft == "CC") return ".cpp";
    if (ft == "RUST") return ".rs";
    if (ft == "JS") return ".js";
    if (ft == "TS") return ".ts";
    if (ft == "PYTHON") return ".py";
    return "unknown-ft";
}
