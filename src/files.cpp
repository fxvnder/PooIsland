#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "files.h"

bool saveFile(const std::string& filename, const file& filereceived) {
    // vars
    std::ofstream saveFile;

    // exporting to file
    try {
        saveFile.open(filename + ".cfg", std::ios::out | std::ios::app);
        saveFile.write((char*)&filereceived, sizeof(filereceived));
        saveFile.close();
        return true;
    } catch (const std::exception& e) {
        std::cout << "ERROR (saving file): " << e.what() << std::endl;
        return false;
    }
}

bool checkFile(const std::string& filename){
    std::ifstream trymefile;
    trymefile.open(filename + ".cfg");
    if(trymefile) {
        return true;
    } else {
        return false;
    }
}

file openFile(const std::string& filename) {
    // vars
    file savedfile;
    std::ifstream openFile(filename + ".cfg");

    // importing from file
    openFile.read((char*)&savedfile, sizeof(savedfile));

    return savedfile;
}
