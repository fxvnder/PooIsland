#ifndef POOISLAND_PROGRAM_H
#define POOISLAND_PROGRAM_H

#include "island.h"
#include "files.h"
#include <vector>
#include <sstream>
#include <iostream>

void game(island& island, file& gamefile);
bool gameover(island& world);
void dawn(island& world);
void dusk(island& world);
int random (int low, int high);
void createNewWorld(int * dim);
void createLoadedWorld(file loadedFile);


#endif //POOISLAND_PROGRAM_H
