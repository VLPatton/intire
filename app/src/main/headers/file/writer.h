/*
 *
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
