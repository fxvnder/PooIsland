#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>
#include "program.h"
#include "files.h"

bool saveFile(const std::string& filename, const file& filereceived) {
    std::ofstream saveFile;
    saveFile.open(filename + ".cfg", std::ios::out | std::ios::app);

//    for (int i = 0; i < commands.size(); i++) {
//        saveFile << commands[i] << "\n";
//    }
//    saveFile.close();
    return true;
}

bool openFile(const std::string& filename) {
    std::string nLines;
    std::ifstream openFile(filename + ".cfg");

    if (openFile.is_open()){
        while (!openFile.eof()) {
            while(getline(openFile, nLines)){
                if (!nLines.empty()) {
                    //treatCommand(nLines, world);
                }
            }
        }
        openFile.close();
        return true;
    } else {
        std::cout << "ERROR: " << strerror(errno) << std::endl;
        return false;
    }
}
