//
// Created by yeshey on 27/11/21.
//

#ifndef POOISLAND_ISLAND_H
#define POOISLAND_ISLAND_H

#include <iostream>
#include <vector>
#include "files.h"
#include "tile.h"
#include "utils.h"

#include "vector.h"

class island {
private:
    int lines = 0, columns = 0;
    int *arr = new int[0];
    //syntax for arr[l][c] will be arr[l*sizeY+c]
    poo::vector<int> array;
    //poo::vector<poo::vector<int>> vecvec{};

    std::vector<std::vector<tile>> vecvec;
public:
    island(int l=0, int c=0);
    std::string showSimpleIsland() const;
    std::string showInfoIsland() const;
    void changeDim(int l, int c);
    tile &Tile(int l, int c);
    std::ostringstream cont(std::vector<std::string> commandsVec);
    std::ostringstream cons(std::vector<std::string> commandsVec);
    bool isOutOfBounds(int l, int c) const;
};

#endif //POOISLAND_ISLAND_H
