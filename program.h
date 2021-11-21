#ifndef POOISLAND_PROGRAM_H
#define POOISLAND_PROGRAM_H
#include "objects.h"
#include <vector>
#include <sstream>
#include <iostream>

void run(int * dim);
void days(island& island);
bool gameover(island& world);
void dawn(island& world);
void plays(island world);
void dusk(island& world);
std::string treatCommand(const std::string& command);

#endif //POOISLAND_PROGRAM_H
