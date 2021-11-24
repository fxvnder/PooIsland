#include <iostream>
#include <vector>
#include <random>
#include "program.h"
#include "objects.h"
#include "files.h"
#include "commands.h"

void createNewWorld(int * dim){
    island world(dim[0], dim[1]);
    file savegame;
    savegame.receiveDim(dim);
    game(world, savegame);
}

void createLoadedWorld(file loadedFile){
    island world(loadedFile.giveLines(), loadedFile.giveColumns());
    std::vector<std::string> oldcommands = loadedFile.redoCommands();
    for (int i = 0; i < oldcommands.size(); ++i) treatCommand(oldcommands[i], world, loadedFile);
    game(world, loadedFile);
}

//class tiles
tile::tile() : building(""), workers() {
    std::vector<std::string> v_types = {"pnt ","dsr ", "pas ", "flr ", "pnt ", "znZ ", "mnF ", "mnC ", "elec", "bat ", "fun "};
    type = v_types[random(0,v_types.size() - 1)];
    // access the island here
}
std::string tile::showInfoTile() const {
    std::ostringstream oss;
    oss << type;
    if (building.empty())
        oss << "    ";
    else
        oss << building;
    oss << "> " << workers[0] << '|' << workers[1] << '|' << workers[2];
    return oss.str();
}
std::string tile::getType(){
    return type;
}
std::string tile::cons(const std::string& command) {
    std::vector<std::string> v_buildings = {"minaf", "minac", "central", "bat", "fund", "edx"};
    std::ostringstream oss;
    for (int i = 0; i < v_buildings.size(); ++i) {
        if (command == v_buildings[i]){
            if (!(building.empty())) {
                oss << "There's a " << building << " here already";
                return oss.str();
            }
            building = command;
            return "";
        }
    }
    oss << "Wrong specified type, the existing types of buildings are: ";
    for (const std::string& str : v_buildings)
        oss << str << ' ';
    return oss.str();
}

std::string tile::cont(const std::string& command){
    std::ostringstream oss;
    std::vector<std::string> v_types = {"miner", "len", "oper"};
    if (type != "pas ")
        return "Can only do this for tiles of type pas";

    for (int i = 0; i < v_types.size(); ++i) {
        if (command == v_types[i]){
            ++workers[i];
            return "";
        }
    }
    oss << "type of worker doesn't exist";
    return oss.str();
}


island::island(int l, int c) : lines(l), columns(c) {
    for (int i = 0; i < l; i++) {
        vecvec.push_back(std::vector<tile>());
        for (int j = 0; j < c; j++) {
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
    oss << "     ";
    for(i=0;i<vecvec.size();i++) // size of columns
        oss << "      C" << i+1 << "      ";
    oss.put('\n');

    oss << "   ";
    for(i=0;i<vecvec.size();i++)
        if(i!=vecvec.size()-1)
            oss << "----------------";
        else
            oss << "-------------------------------";
    oss << '\n';

    for(i=0;i<vecvec[0].size();i++){
        oss << " L" << i+1 << "| ";
        for(j=0;j<vecvec.size()-1;j++){
            oss << "  " << vecvec[i][j].showInfoTile() << " |";
        }
        oss << "  " << vecvec[i][j].showInfoTile() << "  |" << std::endl;

        if(i!=vecvec[0].size()-1){
            oss << "   |-";
            for(j=0;j<vecvec.size()-1;j++)
                oss << "------------------+";
            oss << "-------------------|\n";
        }
    }
    oss << "   ";
    for(i = 0; i < vecvec.size(); i++)
        if(i != vecvec.size() - 1)
            oss << "----------------";
        else
            oss << "-------------------------------";
    oss.put('\n');
    //-----Print the island-----
    return oss.str();
}

std::ostringstream island::cons(std::vector<std::string> commandsVec){ // cons <tipo> <linha> <coluna>
    std::ostringstream oss;
    int l = stoi(commandsVec[2]) ; int c = stoi(commandsVec[2]);
    //if (l >= 1 && l <= vecvec.size()+1 && c >= 1 && c <= vecvec[0].size()+1) { // vecvec.size() size of columns (amount of lines)
        oss << vecvec[l-1][c-1].cons(commandsVec[1]);
        if (oss.str().empty()) {
            oss << "building " << commandsVec[1] << " in X=" << commandsVec[2] << " Y=" << commandsVec[3] << std::endl;
            return oss;
        }
        return oss;
        /*
    } else {
        oss << "Target zone coordinates fall outside the island!";
        return oss;
    }
         */
}

std::ostringstream island::cont(std::vector<std::string> commandsVec) { // cont <type>
    std::ostringstream oss;
    int counter = 0;
    for (int i = 0; i < vecvec.size(); ++i) {
        for (int j = 0; j < vecvec[i].size(); ++j) {
            if (vecvec[i][j].getType() == "pas ")
                ++counter;
        }
    }
    counter = random(1, counter);
    for (int i = 0; i < vecvec.size(); ++i) {
        for (int j = 0; j < vecvec[i].size(); ++j) {
            if (vecvec[i][j].getType() == "pas ") {
                --counter;
                if (counter == 0) {
                    oss << vecvec[i][j].cont(commandsVec[1]);
                }
            }
        }
    }
    if (oss.str().empty())
        oss << "hiring " << commandsVec[1] << std::endl;
    return oss;
}

tile island::getTile(int l, int c) const {
    --l ; --c ;
    return vecvec[l][c];
}

bool island::isOutOfBounds(int l, int c) const{
    --l ; --c ;
    return (l < 0 || l > vecvec.size()-1 || c < 0 || c > vecvec[0].size()-1); // vecvec.size() size of columns (amount of lines)
}
