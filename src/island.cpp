//
// Created by yeshey on 27/11/21.
//

#include "island.h"
#include "tile.h"
#include <iostream>
#include <vector>
#include <random>
#include "program.h"

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
        oss << "        C" << i+1 << "          ";
    oss.put('\n');

    oss << "    ";
    for(i=0;i<vecvec.size();i++)
        if(i==0)
            oss << "+--------------------";
        else
        if(i != vecvec.size() - 1)
            oss << "+-------------------";
        else
            oss << "+--------------------+";
    oss << '\n';

    for(i=0;i<vecvec[0].size();i++){
        oss << " L" << i+1 << " | ";
        for(j=0;j<vecvec.size()-1;j++){
            oss << "  " << vecvec[i][j].showInfoTile() << " |"; // segmetation fault problem
        }
        oss << "  " << vecvec[i][j].showInfoTile() << "  |" << std::endl;

        if(i!=vecvec[0].size()-1){
            oss << "    |-";
            for(j=0;j<vecvec.size()-1;j++)
                oss << "-------------------+";
            oss << "--------------------|\n";
        }
    }
    oss << "    ";
    for(i = 0; i < vecvec.size(); i++)
        if(i==0)
            oss << "+--------------------";
        else
        if(i != vecvec.size() - 1)
            oss << "+-------------------";
        else
            oss << "+--------------------+";
    oss.put('\n');
    //-----Print the island-----
    return oss.str();
}

std::ostringstream island::cons(std::vector<std::string> commandsVec){ // cons <tipo> <linha> <coluna>
    std::ostringstream oss;
    int l = stoi(commandsVec[2]) ; int c = stoi(commandsVec[2]);
    oss << vecvec[l-1][c-1].cons(commandsVec[1]);
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

void island::changeDim(int * dim){ // seg fault
    for (int i = 0; i < dim[0]; i++) { // l
        vecvec.push_back(std::vector<tile>());
        for (int j = 0; j < dim[1]; j++) { // c
            tile newTile;
            vecvec[i].push_back(newTile);
        }
    }
}

tile island::getTile(int l, int c) const {
    --l ; --c ;
    return vecvec[l][c];
}

bool island::isOutOfBounds(int l, int c) const{
    --l ; --c ;
    return (l < 0 || l > vecvec.size()-1 || c < 0 || c > vecvec[0].size()-1); // vecvec.size() size of columns (amount of lines)
}