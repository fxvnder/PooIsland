#ifndef POOISLAND_INTERFACE_H
#define POOISLAND_INTERFACE_H

#include "program.h"

void welcome();
void newGame();
bool loadGame(const std::string& filename);
void plays(const island& world, const file& savegame);
void showCredits();

#endif //POOISLAND_INTERFACE_H
