#include "file_reading.hpp"
#include <fstream>

std::vector<std::string> ReadFile(std::string path) {
    std::vector<std::string> lines;

    std::ifstream file(path);
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(std::move(line));
    }

    return lines;
}
