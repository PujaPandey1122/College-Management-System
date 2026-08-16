#include "../include/FileManager.h"
#include <fstream>
#include <stdexcept>

void FileManager::saveData(const std::string& data) {
    std::ofstream file("data/college_data.txt");

    if (!file) {
        throw std::runtime_error("Unable to open data file for writing.");
    }

    file << data;

    file.close();
}

std::string FileManager::loadData() {
    std::ifstream file("data/college_data.txt");

    if (!file) {
        throw std::runtime_error("Unable to open data file for reading.");
    }

    std::string data;
    std::string line;

    while (std::getline(file, line)) {
        data += line + '\n';
    }

    file.close();

    return data;
}