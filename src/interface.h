#ifndef POOISLAND_INTERFACE_H
#define POOISLAND_INTERFACE_H

#include "program.h"
#include "main2.h"

void welcome();
void newGame();
bool loadGame(const std::string& filename);
void plays(island& world, file& savegame);
void showCredits();
std::string helpMe();

#endif //POOISLAND_INTERFACE_H
