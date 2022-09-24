/*
 * This C++ source file was generated by the Gradle 'init' task.
 */
#ifndef APP_H
#define APP_H

#include <string>
#include "file/reader.h"

namespace intire {
    class Process {
        public:
            Process();
            int useListFile(std::string);
            file::Reader* items;
        private:
            std::string listfile; 
    };
}

#endif