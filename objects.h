#ifndef POOISLAND_OBJECTS_H
#define POOISLAND_OBJECTS_H

#include <iostream>
using std::string;
using std::vector;
using std::endl;

class tile{
private:
    string type;
public:
    tile();
    string showInfoTile() const;
    //friend std::ostream& operator<<(std::ostream& os, const tile& recievedTile); perguntar ao stor
};

class island{
private:
    int lines, columns;
    vector<vector<tile>> vecvec;
    vector<tile> vetr;
public:
    island(int l,int c) : lines(l), columns(c);
    string showInfoIsland() const;
}

#endif //POOISLAND_OBJECTS_H