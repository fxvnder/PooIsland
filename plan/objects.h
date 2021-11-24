#ifndef POOISLAND_OBJECTS_H
#define POOISLAND_OBJECTS_H

#include <iostream>
#include <vector>
#include "files.h"

class tile{
private:
    std::string type;
    std::string building;
    // miner len oper
    int workers[3];
public:
    tile();
    std::string showInfoTile() const;
    std::string cont(const std::string& cmnd);
    std::string getType();
    std::string cons(const std::string& command);
    // friend std::ostream& operator<<(std::ostream& os, const tile& recievedTile);
};

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

void createNewWorld(int * dim);
void createLoadedWorld(file loadedFile);

#endif //POOISLAND_OBJECTS_H
