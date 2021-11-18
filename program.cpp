#include <iostream>
#include "program.h"
#include "objects.h"

void run(int * dim){
    island world(dim[0], dim[1]);
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
