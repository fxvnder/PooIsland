#include <iostream>
#include <fstream>

void saveFile(const std::string& filename) {
    std::ofstream SaveFile;
    SaveFile.open(filename + ".cfg", std::ios::out | std::ios_base::app);
}

void openFile(const std::string& filename) {
    std::string nLines;
    std::ifstream openFile(filename + ".cfg");

    if (openFile.is_open())
    {
        while (!openFile.eof()) {
            getline(openFile, nLines);
        }
        openFile.close();
    }
    else {
        return;
    }
}
