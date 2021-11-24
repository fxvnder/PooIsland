#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include "program.h"
#include "interface.h"
#include "files.h"
#include "objects.h"

//region Working with the island

void game(island& world, file& gamefile){
    do {
        std::cout << world.showInfoIsland() << std::endl;
        dawn(world);
        plays(world, gamefile);
        dusk(world);
    } while (!gameover(world));
}

void dawn(island& world){
    std::cout << "It's dawn..." << std::endl;
}

void dusk(island& world){
    std::cout << "It's dusk..." << std::endl;
}

bool gameover(island& world){
    return false;
}
//endregion

int random (int low, int high) {
    if (low > high) return high;
    std::random_device rd;
    std::default_random_engine e{rd()};
    std::uniform_int_distribution<int> dist{low, high};
    return dist(e);
}

//region ExtraInfo

//    LISTA DE COMANDOS
//    exec <nomeFicheiro>
//    cons <tipo> <linha> <coluna>
//    liga <linha> <coluna>
//    des <linha> <coluna>
//    move <id> <linha> <coluna>
//    vende <tipo> <quanto>
//    cont <tipo>
//    list <linha> <coluna>
//    vende <linha> <coluna>
//    next
//    save <nome>
//    load <nome>
//    apaga <nome>
//    config <ficheiro>
//    debcash <valor>
//    debed <tipo> <linha> <coluna>
//    debkill <id>

//endregion