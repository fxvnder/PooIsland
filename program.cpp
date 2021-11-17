#include <iostream>
#include "program.h"

/*
island::island(int l,int c) : lines(l), columns(c), vec(lines,42) {

};
*/

int run(){
    island world(4,4);
    std::cout << world.showInfoIsland() << std::endl;
    return 0;
}
