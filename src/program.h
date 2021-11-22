#ifndef POOISLAND_PROGRAM_H
#define POOISLAND_PROGRAM_H

#include "objects.h"
#include "files.h"
#include <vector>
#include <sstream>
#include <iostream>

void game(island& island, const file& gamefile);
bool gameover(island& world);
void dawn(island& world);
void dusk(island& world);
std::string treatCommand(const std::string& command, island world, file savegame);


#endif //POOISLAND_PROGRAM_H
