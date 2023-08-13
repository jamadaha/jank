#ifndef JANK_FILE_FILE_READING
#define JANK_FILE_FILE_READING

#include <functional>
#include <string>
namespace Jank::File::FileReading {
std::vector<std::string> ReadFile(std::string path);
}

#endif
