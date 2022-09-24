#include "file/reader.h"
#include <fstream>

using namespace nlohmann;

file::Reader::Reader(std::string filename) {
    std::ifstream file = std::ifstream(filename);
    if (file.fail()) {
        std::printf("[E] intire::Reader::Reader() failed: file.fail() returned true for file %s\n", filename.c_str());
        exit(1);
    }
    data = json::parse(file);
}
