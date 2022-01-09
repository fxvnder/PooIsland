#include "island.h"
#include "tile.h"
#include "program.h"
#include "utils.h"
#include <iostream>
#include <vector>

island::island(int l, int c) {
    for (int i = 0; i < l; i++) {
        vecvec.add(poo::vector<tile*>());
        for (int j = 0; j <= c; j++) {
            vecvec[i].add();
            vecvec[i][j] = randomTile();
        }
    }
}

std::string island::showSimpleIsland() const {
    std::ostringstream oss;
    for (int i = 0; i < vecvec.size(); i++){
        for (int j = 0; j < vecvec[i].size(); j++){
            std::cout << vecvec[i][j]->showInfoTile() << " ";
        }
        std::cout << std::endl;
    }
    return oss.str();
}

std::string island::showInfoIsland() const {
    std::ostringstream oss;
    // vecvec.size(): lines
    // vecvec[i].size(): clomun
    if (vecvec.empty()) // if it's empty, give up
        return oss.str();
    else
        if(vecvec[0].empty())
            return oss.str();

//Exemplo interface:  ┐┌├ ┬ ─│
//
//      1    2    3    4    5
//    ┌────┬────┬────┬────┬────┐
//    │flr │pas │pan │flr │mnt │
//   1│    │elec│    │    │mnF │
//    │LO  │    │    │    │    │
//    │2   │    │    │    │M   │
//    ├────┼────┼────┼────┼────┤
//    │pas │dsr │mnt │flr │mnt │
//   2│    │bat │    │    │    │
//    │    │O   │    │L   │    │
//    │    │1   │    │1   │    │
//    ├────┼────┼────┼────┼────┤
//    │znX │mnt │pnt │dsr │mnt │
//   3│    │mnC │    │    │    │
//    │    │M   │    │    │M   │
//    │    │1   │    │    │1   │
//    ├────┼────┼────┼────┼────┤
//    │mnt │pas │znX │pas │flr │
//   4│    │    │    │    │    │
//    │    │    │    │OOOO│    │
//    │    │    │    │5   │    │
//    └────┴────┴────┴────┴────┘
    for (int j = 1; j <= vecvec.size(); j++){
        if (j==1) { // first iteration
            for (int i = 1; i <= vecvec[0].size(); i++) { // ┌────┬────┬────┬────┬────┐
                if (i == 1) { // first iteration
                    oss << "┌";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                } else if (i == vecvec[0].size()) { // last iteration
                    oss << "┬";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                    oss << "┐" << std::endl;
                } else { // other iteration
                    oss << "┬";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                }
            }
        }

        if (j!=1) { // if not first iteration
            for (int i = 1; i <= vecvec[0].size(); i++) { // ├────┼────┼────┼────┼────┤
                std::string displayvar = vecvec[j - 1][i - 1]->type();
                if (i == 1) { // first iteration
                    oss << "├";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                } else if (i == vecvec[0].size()) { // last iteration
                    oss << "┼";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                    oss << "┤" << std::endl;
                } else { // other iteration
                    oss << "┼";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                }
            }
        }


        for (int i = 1; i <= vecvec[0].size(); i++) { // │flr │pas │pan │flr │mnt │
            std::string displayvar = vecvec[j - 1][i - 1]->type();
            if (i == 1) { // first iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "|" << displayvar;
            } else if (i == vecvec[0].size()) { // last iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "|" << displayvar << "|" << std::endl;
            } else { // other iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "│" << displayvar;
            }
        }

        for (int i = 1; i <= vecvec[0].size(); i++) { // │    │elec│    │    │mnF │
                std::string displayvar = vecvec[j - 1][i - 1]->building();
            if (i == 1) { // first iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "|" << displayvar;
            } else if (i == vecvec[0].size()) { // last iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "|" << displayvar << "|" << std::endl;
            } else { // other iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "│" << displayvar;
            }
        }


        if (j == vecvec.size()){ // last iteration
            for (int i = 1; i <= vecvec[0].size(); i++){ // └────┴────┴────┴────┴────┘

                if (i == 1) { // first iteration
                    oss << "└";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                } else if (i == vecvec[0].size()) { // last iteration
                    oss << "┴";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                    oss << "┘" << std::endl;
                } else { // other iteration
                    oss << "┴";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                }
            }
        }
    }

    return oss.str();
}

std::ostringstream island::cons(std::vector<std::string> commandsVec){ // cons <tipo> <linha> <coluna>
    std::ostringstream oss;
    int l = stoi(commandsVec[2]) ; int c = stoi(commandsVec[2]);
    oss << vecvec[l-1][c-1]->cons(commandsVec[1]);
    if (oss.str().empty()) {
        oss << "building " << commandsVec[1] << " in X=" << commandsVec[2] << " Y=" << commandsVec[3] << std::endl;
        return oss;
    }
    return oss;
}

std::ostringstream island::cont(std::vector<std::string> commandsVec) { // cont <type>
    std::ostringstream oss;
    int counter = 0;
    for (int i = 0; i < vecvec.size(); ++i) {
        for (int j = 0; j < vecvec[i].size(); ++j) {
            if (vecvec[i][j]->type() == "pas")
                ++counter;
        }
    }
    counter = random(1, counter);
    for (int i = 0; i < vecvec.size(); ++i) {
        for (int j = 0; j < vecvec[i].size(); ++j) {
            if (vecvec[i][j]->type() == "pas") {
                --counter;
                if (counter == 0) {
                    oss << vecvec[i][j]->cont(commandsVec[1]);
                }
            }
        }
    }
    if (oss.str().empty())
        oss << "hiring " << commandsVec[1] << std::endl;
    return oss;
}

void island::changeDim(int l, int c){
    for (int i = 0 ; i < l ; ++i ) {
        vecvec.add(poo::vector<class tile*>());
        for (int j = 0; j < c; ++j) {
            vecvec[i].add();
            vecvec[i][j] = randomTile();
        }
    }

    // Check if there's a tile type missing
    for (int i = 0; i < tile_types.size(); ++i){   //std::string type: vecvec[0][0].existingTypes()) {
        std::string typooo = tile_types[i]; //whyNeeded?
        if(!existsInIsland(typooo)){
            i = 0;
            vecvec[random(0,vecvec.size()-1)][random(0,vecvec[0].size()-1)]->type() = typooo;
        }
    }
}

tile * island::randomTile(){
    tile * p;
    int rnd = random(0, tile_types.size()-1);
    mountain ok;
    switch (rnd) {
        case (0):
            p = new mountain;
            break;
        case (1):
            p = new desert;
            break;
        case (2):
            p = new pasture;
            break;
        case (3):
            p = new forest;
            break;
        case (4):
            p = new swamp;
            break;
        case (5):
            p = new zoneX;
            break;
        default:
            std::cout << "Error generating zone" << std::endl;
    }
    return p;
}

bool island::existsInIsland(const std::string type) {
    for (int i = 1; i <= vecvec.size(); i++) {
        for (int j = 1; j <= vecvec[0].size(); j++){
            if (vecvec[i-1][j-1]->type() == type){
                return 1;
            }
        }
    }
    return 0;
}

tile &island::Tile(int l, int c) {
    --l ; --c ;
    return *vecvec[l][c];
}

bool island::isOutOfBounds(int l, int c) const{
    --l ; --c ;
    return (l < 0 || l > vecvec.size()-1 || c < 0 || c > vecvec[0].size()-1); // vecvec.size() size of columns (amount of lines)
}