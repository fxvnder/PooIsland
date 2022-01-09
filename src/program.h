#ifndef POOISLAND_PROGRAM_H
#define POOISLAND_PROGRAM_H

#include "island.h"
#include "files.h"
#include <vector>
#include <sstream>
#include <iostream>

class gameData {
private:
    island world;
    std::vector<std::string> resources;
    std::vector<int> resources_quantities;
public:
    gameData();
    void createNewWorld(int *dim);
    void dawn();
    void dusk();
    bool over();
    island &Island();
    void readConfigFile(std::string filename);
    void readExecFile(std::string filename);
};

//void createLoadedWorld(file loadedFile);

#endif //POOISLAND_PROGRAM_H