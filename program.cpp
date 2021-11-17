#include <iostream>
#include "program.h"

// classe tile
/*
std::ostream& operator<<(std::ostream& os, const tile& recievedTile){
    os << recievedTile.type;
    return os;
}
 */

//class island
/*
island::island(int l,int c) : lines(l), columns(c), vec(lines,42) {
};
*/

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
    //friend std::ostream& operator<<(std::ostream& os, const tile& recievedTile); perguntar ao stor
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
        return oss.str();
    };
};

void run(int * dim){
    island world(dim[0],dim[1]);
    days(world);
}

void days(island world){
    do {
        std::cout << world.showInfoIsland() << std::endl;
        dawn(world);
        plays(world);
        dusk(world);
    } while (!gameover(world));
}

void dawn(island world){
    std::cout << "dawn" << std::endl; //dw founder this is not interface
}

void dusk(island world){
    std::cout << "dusk" << std::endl; //dw founder this is not interface
}

bool gameover(island world){
    return false;
}