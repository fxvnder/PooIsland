#ifndef POOISLAND_PROGRAM_H
#define POOISLAND_PROGRAM_H
#include "objects.h"
#include <vector>
#include <sstream>
#include <iostream>

void run(int * dim);
void days(const island& island);
bool gameover(const island& world);
void dawn(const island& world);
void plays(island world);
void dusk(const island& world);
std::string treatCommand(std::string command, island island);

#endif //POOISLAND_PROGRAM_H
