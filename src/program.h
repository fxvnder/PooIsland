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
public:
    gameData();
    void createNewWorld(int * dim);
    void dawn();
    void dusk();
    bool over();
    island &Island();
};

int random (int low, int high);
void createLoadedWorld(file loadedFile);


#endif //POOISLAND_PROGRAM_H