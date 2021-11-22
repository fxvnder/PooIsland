#ifndef POOISLAND_OBJECTS_H
#define POOISLAND_OBJECTS_H

#include <iostream>
#include <vector>

class tile{
private:
    int merda;
    std::string type;
    std::string building;
public:
    tile();
    std::string showInfoTile() const;
    std::string cons(std::string cmnd);
    // friend std::ostream& operator<<(std::ostream& os, const tile& recievedTile); perguntar ao stor
};

class island : public tile { // herança
private:
    int lines, columns;
    std::vector<std::vector<tile>> vecvec;
public:
    island(int l,int c);
    std::string showInfoIsland() const;
    std::ostringstream cons(std::vector<std::string> commandsVec);
};

void createNewWorld(int * dim);
void createLoadedWorld(int * dim);

#endif //POOISLAND_OBJECTS_H
