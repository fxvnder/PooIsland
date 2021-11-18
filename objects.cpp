#include "objects.h"
#include <iostream>
#include <sstream>
#include <vector>

//class tiles
tile::tile() : type("forest") {};
string tile::showInfoTile() const {
    std::ostringstream oss;
    oss << type;
    return oss.str();
};

//class island
island::island(int l,int c) : lines(l), columns(c) {
    for (int i = 0; i < l; ++i) {
        vecvec.push_back(std::vector<tile>());
        for (int j = 0; j < c; ++j) {
            tile newTile;                       // todo: find a better way, maybe use new
            vecvec[i].push_back(newTile);
        }
    }
};

string island::showInfoIsland() const {
    std::ostringstream oss;
    oss << "Showing Island Info" << endl;
    for (const std::vector<tile> &vec : vecvec){
        for (const tile &x : vec)
            oss << x.showInfoTile() << " ";
        oss << endl;
    }
    return oss.str();
};


/*
std::ostream& operator<<(std::ostream& os, const tile& recievedTile){
    os << recievedTile.type;
    return os;
}
 */
