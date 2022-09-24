/*

Copyright 2022 Charlotte Patton

This file is part of Intire.

Intire is free software: you can redistribute it and/or modify it under the terms of the
GNU General Public License as published by the Free Software Foundation, either
version 3 of the License, or (at your option) any later version.

Intire is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with Intire. If
not, see <https://www.gnu.org/licenses/>. 

*/

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
