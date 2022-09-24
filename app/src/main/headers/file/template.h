/*
 *
 */

#include <map>
#include <nlohmann/json.hpp>
#include <string>
#include <sstream>
#include <vector>
#include "reader.h"

namespace file {
    enum DataTypes {
        kINT = 0,
        kSTRING,
        kDOUBLE
    };

    class Category {
        public:
            // General
            Category(std::string, Reader);         // Select a category out of the Reader object to read from
            std::string pprint();                   // Print the current category's ID'd objects based on its template object
            int setID(std::string);                 // Set the current ID to a specific one (need not be valid)
            std::vector<std::string> getIDs();      // Get all of the valid IDs within the category
            std::vector<std::string> getKeys();     // Get the keys of the currently selected ID
            // Assign/read to a key a specific value
            int addStr(std::string, std::string);
            std::string getStr(std::string);
            int addInt(std::string, int);
            int getInt(std::string);
            int addDouble(std::string, double);
            double getDouble(std::string);
            // Get attributes about a specific key within the current ID
            std::string getPrettyName(std::string);
            std::string getSuffix(std::string); 
        private:
            std::string category;
            std::string currentID;
            std::stringstream* output;
            std::vector<std::string>* allIDs;
            std::vector<std::string>* keys;
            std::map<std::string, int>* keytypes;
            std::map<std::string, int>* availtypes;
            nlohmann::json data_template;
            nlohmann::json data;
    };
}
