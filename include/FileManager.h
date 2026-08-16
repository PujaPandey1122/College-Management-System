#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <string>

class FileManager {
public:
    static void saveData(const std::string& data);
    static std::string loadData();
};

#endif