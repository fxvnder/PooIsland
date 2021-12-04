//
// Created by yeshey on 27/11/21.
//

#ifndef POOISLAND_ISLAND_H
#define POOISLAND_ISLAND_H

#include <iostream>
#include <vector>
#include "files.h"
#include "tile.h"

class island {
private:
    std::vector<std::vector<tile>> vecvec;
public:
    island(int l=0,int c=0);
    std::string showSimpleIsland() const;
    std::string showInfoIsland() const;
    void changeDim(int l, int c);
    tile getTile(int l, int c) const;
    std::ostringstream cont(std::vector<std::string> commandsVec);
    std::ostringstream cons(std::vector<std::string> commandsVec);
    bool isOutOfBounds(int l, int c) const;
};

#endif //POOISLAND_ISLAND_H
