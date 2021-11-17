#ifndef POOISLAND_PROGRAM_H
#define POOISLAND_PROGRAM_H
#include <vector>
#include <sstream>
#include <iostream>

class tile{
private:
    std::string type;
public:
    tile() : type("forest") {};
    std::string showInfoTile() const {
        std::ostringstream oss;
        oss << type;
        return oss.str();
    };
    //friend std::ostream& operator<<(std::ostream& os, const tile& recievedTile);
};

class island{
private:
    int lines, columns;
    std::vector<std::vector<tile>> vecvec;
    std::vector<tile> vetr;
public:
    island(int l,int c) : lines(l), columns(c) {
        for (int i = 0; i < l; ++i) {
            vecvec.push_back(std::vector<tile>());
            for (int j = 0; j < c; ++j) {
                tile newTile;                       // todo: find a better way, maybe use new
                vecvec[i].push_back(newTile);
            }
        }
    };
    std::string showInfoIsland() const {
        std::ostringstream oss;
        oss << "Showing Island Info" << std::endl;
        for (std::vector<tile> vec : vecvec){
            for (tile x : vec)
                oss << x.showInfoTile() << " ";
            oss << std::endl;
            }
        /*
        for (int i = 0; i < vecvec.size(); i++){
            for (int j = 0; j < vecvec[i].size(); j++){
                oss << vecvec[i][j].showInfoTile() << " ";
            }
            oss << std::endl;
        }
         */
        return oss.str();
    };
};

void run(int * dim);

#endif //POOISLAND_PROGRAM_H
