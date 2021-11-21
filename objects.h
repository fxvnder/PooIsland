#ifndef POOISLAND_OBJECTS_H
#define POOISLAND_OBJECTS_H

#include <iostream>
#include <vector>

using std::string;
using std::endl;

class tile{
private:
    string type;
public:
    tile();
    string showInfoTile() const;
    //friend std::ostream& operator<<(std::ostream& os, const tile& recievedTile); perguntar ao stor
};

class island : public tile { //herança
private:
    int lines, columns;
    std::vector<std::vector<tile>> vecvec;
public:
    island(int l,int c);
    string showInfoIsland() const;
    int getl();
    int getc();
};

#endif //POOISLAND_OBJECTS_H
