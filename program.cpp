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
    std::cout << world.showInfoIsland() << std::endl;
}
