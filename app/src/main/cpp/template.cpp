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

#include "file/template.h"
#include <sstream>

file::Category::Category(std::string cat, file::Reader reader) {
    category = cat;
    data = reader.data[category];
    data_template = reader.data[category]["template"];  // Find the template JSON object
    
    // Iterate through the items within the template object until all base keys are found
    keys = std::make_unique<std::vector<std::string>>();
    for (const auto& elements : data_template.items()) {
        keys->push_back(elements.key());
    }

    availtypes = std::make_unique<std::map<std::string, int>>();
    (*availtypes)["kINT"] = kINT;
    (*availtypes)["kSTRING"] = kSTRING;
    (*availtypes)["kDOUBLE"] = kDOUBLE;

    allIDs = std::make_unique<std::vector<std::string>>();
    for (const auto& ids : data.items()) {
        if (ids.key() != "template")
            allIDs->push_back(ids.key());
    }
}

std::string file::Category::pprint() {
    output = std::stringstream();

    for (unsigned int i = 0; i < allIDs->size(); i++) {
        setID((*allIDs)[i]);
        //std::printf("[D] file::Category::pprint() : (*allIDs)[i] == \"%s\"\n", (*allIDs)[i].c_str()); // NOTE: for debug
        output << "Current ID: " << (*allIDs)[i] << ":\n";
        for (unsigned int j = 0; j < keys->size(); j++) {
            //std::printf("[D] file::Category::pprint() : (*keys)[j] == \"%s\"\n", (*keys)[j].c_str()); // NOTE: for debug
            switch ((*availtypes)[data_template[(*keys)[j]]["type"]]) {
                case kINT:
                    output << "    " << getPrettyName((*keys)[j]) << ": " 
                    << getInt((*keys)[j]) << getSuffix((*keys)[j]) << "\n";
                    break;
                case kSTRING:
                    output << "    " << getPrettyName((*keys)[j]) << ": "
                    << getStr((*keys)[j]) << getSuffix((*keys)[j]) << "\n";
                    break;
                case kDOUBLE:
                    output << "    " << getPrettyName((*keys)[j]) << ": "
                    << getDouble((*keys)[j]) << getSuffix((*keys)[j]) << "\n";
                    break;
            }
        }
    }

    return output.str();
}

int file::Category::setID(std::string id) {
    currentID = id;

    return 0;
}

std::string file::Category::getPrettyName(std::string key) {
    return data_template[key]["pretty_name"];
}

int file::Category::getInt(std::string key) {
    int ret = -1;
    if ((*availtypes)[data_template[key]["type"]] != kINT)
        return -1;
    ret = data[currentID][key];
    return ret;
}

std::string file::Category::getStr(std::string key) {
    std::string ret = "";
    if ((*availtypes)[data_template[key]["type"]] != kSTRING)
        return "";
    ret = data[currentID][key];
    return ret;
}

double file::Category::getDouble(std::string key) {
    double ret = -1.0;
    if ((*availtypes)[data_template[key]["type"]] != kSTRING)
        return -1.0;
    ret = data[currentID][key];
    return ret;
}

std::string file::Category::getSuffix(std::string key) {
    return data_template[key]["suffix"];
}
