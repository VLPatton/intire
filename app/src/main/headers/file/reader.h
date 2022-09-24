/*
 *
 */

#pragma once

#include <nlohmann/json.hpp>
#include <string>

namespace file {
    class Reader {
        public:
            Reader(std::string);
            nlohmann::json data;
    };
}
