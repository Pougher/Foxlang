#include "file.hpp"

std::string File::load_file(const char* filename)
{
    std::ifstream file(filename);
    std::stringstream stream;

    if (!file.good()) {
        std::cerr << "IOError: File '" << filename << "' could not be opened" \
            << std::endl;
        std::exit(1);
    }

    stream << file.rdbuf();

    return stream.str();
}

void File::write_file(const std::string& filename, const std::string& file_data)
{
    std::ofstream file(filename);
    file << file_data;
    file.close();
}
