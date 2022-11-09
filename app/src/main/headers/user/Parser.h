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

#include <string>
#include <vector>

/**
 * @namespace user
 * @brief 
 *      This namespace contains user interface classes and declarations.
 */
namespace user {
    enum CmdSwitches {
        kLIST = 0,
        kVERSION,
        kHELP,
        kEDIT,
        kADD,
        kREMV,
        kCATEGORY_EDIT
    };

    /**
     * @class Parser
     * @brief 
     *      This class uses the arg count and arg vector and converts it to a 
     *      command and supplies a file and scanner to use during the program.
     *
     * Everything is done through the constructor and the public variables can 
     * be used to access the command and other components.
     */
    class Parser {
        public:
            /**
             * @brief 
             *      Constructor for Parser class. This uses the argc and argv 
             *      with regex to determine what each thing should be.
             *
             * Parameters should be passed either from the parent class, or the 
             * main method.
             * @param argc
             *      The argc passed from the main method.
             * @param argv
             *      The argv passed from the main method.
             */
            Parser(int argc, char* argv[]);
            
            /**
             * @brief 
             *      The command to be executed by the process.
             *
             * This follows the CmdSwitches enum type.
             */
            CmdSwitches command = kHELP;

            /**
             * @brief 
             *      The filename to use as the database file.
             * 
             * This string represents the given file name in the CLI
             */
            std::string file = "";
            std::string scanner = "";   // To be implemented
            std::vector<std::string>* args;
    };
}
