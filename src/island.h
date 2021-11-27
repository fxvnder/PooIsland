//
// Created by yeshey on 27/11/21.
//

#ifndef POOISLAND_ISLAND_H
#define POOISLAND_ISLAND_H

#include <iostream>
#include <vector>
#include "files.h"
#include "tile.h"

class island { // herança
private:
    int lines, columns;
    std::vector<std::vector<tile>> vecvec;
public:
    island(int l,int c);
    std::string showInfoIsland() const;
    tile getTile(int l, int c) const;
    std::ostringstream cont(std::vector<std::string> commandsVec);
    std::ostringstream cons(std::vector<std::string> commandsVec);
    bool isOutOfBounds(int l, int c) const;
};

#endif //POOISLAND_ISLAND_H
