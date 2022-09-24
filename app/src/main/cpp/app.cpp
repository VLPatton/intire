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

intire::Process::Process() {
    useListFile(
        /*
        (std::getenv("HOME") == NULL ? "" : std::getenv("HOME")) 
        + std::string("/.config/intire/items.json")
        */
        std::string("items.json")
    );
    items = new file::Reader(listfile);
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

int main(int argc, char* argv[]) {
    intire::Process* proc = new intire::Process();
    file::Category* hdd = new file::Category("HDD", *(proc->items));
    std::printf("%s\n", hdd->pprint().c_str());
    delete hdd;
    delete proc;
    return 0;
}
