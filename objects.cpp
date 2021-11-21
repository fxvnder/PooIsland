#include "objects.h"
#include <iostream>
#include <sstream>
#include <vector>

using std::ostringstream;
using std::vector;

//class tiles
tile::tile() {
    vector<string> v_types = {"pnt ","dsr ", "pas ", "flr ", "pnt ", "znZ ", "mnF ", "mnC ", "elec", "bat ", "fun "};
    type = v_types[ rand()%(v_types.size()) ];
    // access the island here
};
string tile::showInfoTile() const {
    ostringstream oss;
    oss << type;
    return oss.str();
};

//class island
island::island(int l,int c) : lines(l), columns(c) {
    for (int i = 0; i < l; ++i) {
        vecvec.push_back(vector<tile>());
        for (int j = 0; j < c; ++j) {
            tile newTile;
            vecvec[i].push_back(newTile);
        }
    }
};
string island::showInfoIsland() const {
    ostringstream oss;
    oss << "Showing Island Info" << endl;
    for (const vector<tile> &vec : vecvec){
        for (const tile &x : vec)
            oss << x.showInfoTile() << " ";
        oss << endl;
    }
    return oss.str();
};



/*
std::ostream& operator<<(std::ostream& os, const tile& receivedTile){
    os << receivedTile.type;
    return os;
}
 */
