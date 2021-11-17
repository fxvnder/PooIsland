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