#include <iostream>
#include <vector>
#include "program.h"
#include "objects.h"
#include "files.h"

void createNewWorld(int * dim){
    island world(dim[0], dim[1]);
    file savegame;
    savegame.receiveDim(dim);
    game(world, savegame);
}

void createLoadedWorld(int * dim){
    island world(dim[0], dim[1]);
    file savegame;
    savegame.receiveDim(dim);
    game(world, savegame);
}

//class tiles
tile::tile() {
    std::vector<std::string> v_types = {"pnt ","dsr ", "pas ", "flr ", "pnt ", "znZ ", "mnF ", "mnC ", "elec", "bat ", "fun "};
    type = v_types[ rand()%(v_types.size()) ];
    // access the island here
}

std::string tile::showInfoTile() const {
    std::ostringstream oss;
    oss << type;
    return oss.str();
}

std::string tile::cons(std::string cmnd) {
    std::vector<std::string> v_buildings = {"minaf", "minac", "central", "bat", "fund", "edx"};
    std::ostringstream oss;
    for (int i = 0; i < v_buildings.size(); ++i) {
        if (cmnd == v_buildings[i]){
            building = cmnd;
            return "";
        }
    }
    return "Specified type doesn't exist";
}


//class island
island::island(int l,int c) : lines(l), columns(c) {
    for (int i = 0; i < l; ++i) {
        vecvec.push_back(std::vector<tile>());
        for (int j = 0; j < c; ++j) {
            tile newTile;
            vecvec[i].push_back(newTile);
        }
    }
}

std::string island::showInfoIsland() const {
    // vars
    std::ostringstream oss;
    oss << "Showing Island Info" << std::endl;
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
        oss << ' ' << vecvec[i][j].showInfoTile() << "  |" << std::endl;

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

std::ostringstream island::cons(std::vector<std::string> commandsVec, island world){ // cons <tipo> <linha> <coluna>
    std::ostringstream oss;
    int l = stoi(commandsVec[2]) ; int c = stoi(commandsVec[2]);
    oss << vecvec[stoi(commandsVec[2])][stoi(commandsVec[3])].cons(commandsVec[1]);
    if (oss.str().empty()) {
        oss << "building " << commandsVec[1] << " in X=" << commandsVec[2] << " Y=" << commandsVec[3] << std::endl;
        return oss;
    }
    return oss;
}