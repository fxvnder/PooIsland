#include "objects.h"
#include <iostream>
#include <sstream>
#include <vector>

using std::ostringstream;
using std::vector;
using std::cout;
using std::endl;

//class tiles
tile::tile() {
    vector<string> v_types = {"pnt ","dsr ", "pas ", "flr ", "pnt ", "znZ ", "mnF ", "mnC ", "elec", "bat ", "fun "};
    type = v_types[ rand()%(v_types.size()) ];
    // access the island here
}

string tile::showInfoTile() const {
    ostringstream oss;
    oss << type;
    return oss.str();
}

std::string tile::cons(std::string cmnd) {
    vector<string> v_buildings = {"minaf", "minac", "central", "bat", "fund", "edx"};
    std::ostringstream oss;
    for (auto & v_building : v_buildings) {
        if (cmnd == v_building){
            building = cmnd;
            return "";
        }
    }
    return "Wrong type";
}


//class island
island::island(int l,int c) : lines(l), columns(c) {
    for (int i = 0; i < l; ++i) {
        vecvec.push_back(vector<tile>());
        for (int j = 0; j < c; ++j) {
            tile newTile;
            vecvec[i].push_back(newTile);
        }
    }
}

string island::showInfoIsland() const {
    // vars
    ostringstream oss;
    oss << "Showing Island Info" << endl;
    int i=0,j=0;

    /*for (const vector<tile> &vec : vecvec){
        for (const tile &x : vec)
            oss << x.showInfoTile() << ' ';
        oss << endl;
    }*/

    //-----Print the island-----
    oss << "   ";
    for(i=0;i<vecvec.size();i++) // size of columns
        oss << "   C" << i << "   ";
    oss.put('\n');

    oss << "   ";
    for(i=0;i<vecvec.size();i++)
        if(i!=vecvec.size()-1)
            oss << "--------";
        else
            oss << "--------";
    oss << '\n';

    for(i=0;i<vecvec[0].size();i++){
        oss << "L" << i << '|';
        for(j=0;j<vecvec.size()-1;j++){
            oss << "  " << vecvec[i][j].showInfoTile() << " :";
        }
        oss << ' ' << vecvec[i][j].showInfoTile() << "  |" << endl;

        if(i!=vecvec[0].size()-1){
            oss << "  |";
            for(j=0;j<vecvec.size()-1;j++)
                oss << "-------:";
            oss << "-------|\n";
        }
    }
    oss << "   ";
    for(i = 0; i < vecvec.size(); i++)
        if(i != vecvec.size() - 1)
            oss << "--------";
        else
            oss << "--------";
    oss.put('\n');
    //-----Print the island-----
    return oss.str();
}

ostringstream island::cons(vector<string> commandsVec, island world){ // cons <tipo> <linha> <coluna>
    ostringstream oss;
    oss << vecvec[stoi(commandsVec[3])][stoi(commandsVec[4])].cons(commandsVec[1]);
    if (oss.str().empty()) {
        oss << "building " << commandsVec[1] << " in X=" << commandsVec[2] << " Y=" << commandsVec[3] << endl;
        return oss;
    }
    return oss;
}

// random code that might be useful someday (or not)

/*
std::ostream& operator<<(std::ostream& os, const tile& receivedTile){
    os << receivedTile.type;
    return os;
}
*/
