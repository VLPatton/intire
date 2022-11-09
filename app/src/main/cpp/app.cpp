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

#include <fstream>
#include <cstdio>
#include <cstdlib>
#include "app.h"
#include "file/reader.h"
#include "file/template.h"

#ifndef _INTIRE_VER
#define _INTIRE_VER "0.0.0-rc0"
#endif

intire::Process::Process(int argc, char* argv[]) : parser(argc, argv) {
    useListFile(
        /*
        (std::getenv("HOME") == NULL ? "" : std::getenv("HOME")) 
        + std::string("/.config/intire/items.json")
        */
        std::string("items.json")
    );
}

int intire::Process::useListFile(std::string file) {
    std::fstream check = std::fstream(file, std::ios_base::in);
    if (check.fail()) {
        std::printf("[E] intire::Process::useListFile() failed: check.fail() returned true for file %s\n", file.c_str());
        exit(1);
    }
    listfile = file;
    return 0;
}

int intire::Process::exec() {
    int ret = 0;

    switch (parser.command) {
        case user::CmdSwitches::kHELP:
            std::printf("Usage: intire (COMMAND) [OPTIONS]\n");
            std::printf("  COMMAND:\n");
            std::printf("    -l, --list         Lists the items within the JSON file\n");
            std::printf("    -h, --help         Prints this message\n");
            std::printf("    -v, --version      Prints the version number\n");
            std::printf("    -a, --add          Adds an item to the JSON file based on time and random UUID and scanner info\n");
            std::printf("    -e, --edit         Edits the attributes of an item in the JSON file\n");
            std::printf("    -r, --remove       Removes an item from the JSON file\n");
            std::printf("  OPTIONS:\n");
            std::printf("    -f, --file         Specifies a JSON file to use for the database of items/categories\n");
            std::printf("    -s, --with-scanner Specifies the IP address of the scanner server (TO BE IMPLEMENTED)\n");
            break;
        case user::CmdSwitches::kVERSION:
            std::printf("%s\n", _INTIRE_VER);
            break;
        case user::CmdSwitches::kREMV:
            break;
        case user::CmdSwitches::kADD:
            break;
        case user::CmdSwitches::kEDIT:
            break;
        case user::CmdSwitches::kLIST:
            break;
        case user::CmdSwitches::kCATEGORY_EDIT:
            break;
        default:
            std::printf("Usage: intire (COMMAND) [OPTIONS]\n");
            std::printf("  COMMAND:\n");
            std::printf("    -l, --list         Lists the items within the JSON file\n");
            std::printf("    -h, --help         Prints this message\n");
            std::printf("    -v, --version      Prints the version number\n");
            std::printf("    -a, --add          Adds an item to the JSON file based on time and random UUID and scanner info\n");
            std::printf("    -e, --edit         Edits the attributes of an item in the JSON file\n");
            std::printf("    -r, --remove       Removes an item from the JSON file\n");
            std::printf("  OPTIONS:\n");
            std::printf("    -f, --file         Specifies a JSON file to use for the database of items/categories\n");
            std::printf("    -s, --with-scanner Specifies the IP address of the scanner server (TO BE IMPLEMENTED)\n");
            break;
    }

    return ret;
}

int main(int argc, char* argv[]) {
    intire::Process proc{argc, argv};
    int ret = proc.exec();
    return ret;
}
