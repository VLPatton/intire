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

#include "user/Parser.h"
#include <regex>
#include <cstdio>

user::Parser::Parser(int argc, char* argv[]) {
    std::string cmdline = "";
    args = new std::vector<std::string>();

    for (int i = 0; i < argc; i++) {
        std::string arg = std::string(argv[i]);
        args->push_back(arg);
        cmdline = cmdline + arg + " ";
    }

    std::regex find_file{ "(-f|--file)\\s(\\S+)" };
    std::regex find_scanner{ "(-s|--with-scanner)\\s(\\S+)" };
    std::regex find_command{"-[lhvaerc]|(--(list|help|version|add|edit|remove|category\\-edit))"};
    std::smatch find_res{};

    if (!std::regex_search(cmdline, find_res, find_command)) {
        if (!find_res.ready()) {
            std::printf("[D] user::Parser::Parser() : find_res.ready() returned false!\n");
        } else {
            std::printf("[D] user::Parser::Parser() : No match for command\n");
            std::printf("[D] user::Parser::Parser() : cmdline = \"%s\"\n", cmdline.c_str());
            return;
        }
    }
    
    std::string command_str = find_res.str();
    if (command_str == "--list" || command_str == "-l") {
        command = kLIST;
    } else if (command_str == "--help" || command_str == "-h") {
        command = kHELP;
        return;
    } else if (command_str == "--version" || command_str == "-v") {
        command = kVERSION;
        return;
    } else if (command_str == "--add" || command_str == "-h") {
        command = kADD;
    } else if (command_str == "--edit" || command_str == "-e") {
        command = kEDIT;
    } else if (command_str == "--remove" || command_str == "-r") {
        command = kREMV;
    } else if (command_str == "--category-edit" || command_str == "-c") {
        command = kCATEGORY_EDIT;
    }

    if (std::regex_match(cmdline, find_res, find_file)) {
        file = find_res[2].str();
    }

    if (std::regex_match(cmdline, find_res, find_scanner)) {
        scanner = find_res[2].str();
    }
}
