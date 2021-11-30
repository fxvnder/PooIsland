#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include "program.h"
#include "interface.h"
#include "files.h"
#include "commands.h"

gameData::gameData(){
}
island gameData::getIsland(){
    return world;
};

//region Working with the island

void gameData::createNewWorld(int * dim){
    island world(dim[0], dim[1]);
    //world.changeDim(dim);
    //world.showInfoIsland();
    //exit(0)
    file savegame;
    savegame.receiveDim(dim);
    game(world, savegame);
}

void createLoadedWorld(file loadedFile){
    island world(loadedFile.giveLines(), loadedFile.giveColumns());
    std::vector<std::string> oldcommands = loadedFile.getCommands();
    for (int i = 0; i < oldcommands.size(); ++i) treatCommand(oldcommands[i], world, loadedFile);
    game(world, loadedFile);
}

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