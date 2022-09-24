#include "file/writer.h"

file::Writer::Writer(std::string file, nlohmann::json data_in) {
    filename = file;
    data = data_in;
}


