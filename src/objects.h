#ifndef POOISLAND_OBJECTS_H
#define POOISLAND_OBJECTS_H

#include <iostream>
#include <vector>

class tile{
private:
    std::string type;
    std::string building;
    // miners lens opers
    //int workers[3];
public:
    tile();
    std::string showInfoTile() const;
    std::string getType();
    // friend std::ostream& operator<<(std::ostream& os, const tile& recievedTile); TODO: perguntar ao stor
};

class island : public tile { // herança
private:
    int lines, columns;
    std::vector<std::vector<tile>> vecvec;
public:
    island(int l,int c);
    std::string showInfoIsland() const;
};

void createNewWorld(int * dim);
void createLoadedWorld(int * dim);

#endif //POOISLAND_OBJECTS_H
