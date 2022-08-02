#pragma once

#include <iostream>
#include <fstream>
#include <sstream>

/* namespace for file management */
namespace File {
    /* Function to load the file `filename` into
    * memory as an std::string. */
    std::string load_file(const char* filename);

    /* Function to write data to a file */
    void write_file(const std::string& filename, const std::string& file_data);
}
