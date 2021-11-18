#include <iostream>
#include "program.h"
#include "objects.h"

void run(int * dim){
    island world(dim[0], dim[1]);
    days(world);
}

void days(const island& world){
    do {
        std::cout << world.showInfoIsland() << std::endl;
        dawn(world);
        plays(world);
        dusk(world);
    } while (!gameover(world));
}

void dawn(const island& world){
    std::cout << "dawn" << std::endl; //dw founder this is not interface ok mano
}

void dusk(const island& world){
    std::cout << "dusk" << std::endl; //dw founder this is not interface na boa mpt
}

bool gameover(const island& world){
    return false;
}
