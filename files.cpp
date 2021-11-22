#include <iostream>
#include <fstream>
#include <vector>

void saveFile(const std::string& filename, std::vector<std::string> commands) {
    std::ofstream saveFile;
    saveFile.open(filename + ".cfg", std::ios::out | std::ios_base::app);
    for (int i = 0; i < commands.size(); i++) {
        saveFile << commands[i] << "\n";
    }
    saveFile.close();
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
