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

#ifndef APP_H
#define APP_H

#include <string>
#include <vector>
#include "user/Parser.h"
#include "file/reader.h"

namespace intire {
    class Process {
        public:
            Process(int argc, char* argv[]);
            int useListFile(std::string);
            int exec(); 
        private:
            user::Parser parser;
            std::string listfile{"items.json"};
            file::Reader items{listfile};
    };
}

#endif
