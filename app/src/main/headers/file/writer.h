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

#pragma once

#include <fstream>
#include <nlohmann/json.hpp>

namespace file {
    class Writer {
        public:
            Writer(std::string, nlohmann::json);
            ~Writer();
            int update(nlohmann::json);
            int finalize();

            std::string stringdata;
            std::string filename;
            nlohmann::json data;
    };
}
