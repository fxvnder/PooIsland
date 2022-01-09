#include "program.h"
#include "files.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <fstream>


gameData::gameData(){
    resources.push_back("Iron"); //Ferro
    resources.push_back("Steel bar"); //Barra de aço
    resources.push_back("Coal"); //Carvão
    resources.push_back("Wood"); //Madeira
    resources.push_back("Wood Plaques"); //Madeira
    resources.push_back("Electricity"); //Eletricidade

    for (std::string s : resources)
        resources_quantities.push_back(0);
}
island &gameData::Island(){
    return world;
};

void gameData::createNewWorld(int * dim){
    world.changeDim(dim[0], dim[1]);
    //file savegame;
    //savegame.receiveDim(dim);
    //game(savegame);
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

void gameData::readConfigFile(std::string filename){
    return;
}

void gameData::readExecFile(std::string filename){
// vars
    int commandnum = 1;
    std::string lineContent;
    std::ifstream fileSaved(filename + ".cfg");
    std::string msg;

    if (fileSaved.is_open()) {
        while (getline(fileSaved, lineContent)) {
            std::cout << "\nCommand #" << commandnum << ":" << std::endl;
            std::cout << lineContent << "\n" << std::endl; // prints out everything
            if (!lineContent.empty()) {
                msg = treatCommand(lineContent);
                std::cout << msg << std::endl;
                commandnum++;
            }
        }
        fileSaved.close();
    } else {
        std::cout << "ERROR: " << strerror(errno) << std::endl;
    }
    return;
}

// void createLoadedWorld(file loadedFile){
//     island world(loadedFile.giveLines(), loadedFile.giveColumns());
//     std::vector<std::string> oldcommands = loadedFile.getCommands();
//     //for (int i = 0; i < oldcommands.size(); ++i) treatCommand(oldcommands[i]); //treatCommand(oldcommands[i], world, loadedFile);
//     //game(world, loadedFile);
// }

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