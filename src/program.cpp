#include "program.h"
#include "files.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <random>

gameData::gameData(){
}
island gameData::getIsland(){
    return world;
};

void gameData::createNewWorld(int * dim){
    world.changeDim(dim[0], dim[1]);
    //file savegame;
    //savegame.receiveDim(dim);
    //game(savegame);
}

void createLoadedWorld(file loadedFile){
    island world(loadedFile.giveLines(), loadedFile.giveColumns());
    std::vector<std::string> oldcommands = loadedFile.getCommands();
    //for (int i = 0; i < oldcommands.size(); ++i) treatCommand(oldcommands[i]); //treatCommand(oldcommands[i], world, loadedFile);
    //game(world, loadedFile);
}

void gameData::dawn(){
    std::cout << "It's dawn..." << std::endl;
}

void gameData::dusk(){
    std::cout << "It's dusk..." << std::endl;
}

bool gameData::over(){
    return false;
}

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