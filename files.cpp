#include <iostream>
#include <fstream>
#include "files.h"

void saveFile(std::string filename) {
    std::ofstream SaveFile;
    SaveFile.open(filename + ".cfg", std::ios::out | std::ios_base::app);
}

void openFile(std::string filename) {
    std::string nLines;
    std::ifstream OpenFile(filename + ".cfg");

    if (OpenFile.is_open())
    {
        while (!OpenFile.eof()) {
            getline(OpenFile, nLines);
        }
        OpenFile.close();
    }
    else {
        return;
    }
}
