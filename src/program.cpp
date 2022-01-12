#include "program.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <fstream>



gameData::gameData() :
    iron(0),
    steel_bar(0),
    coal(0),
    wood(0),
    wood_plaques(0),
    resources(0) { }

Island &gameData::island(){
    return world;
}

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

// STUFF WITH FILES

void gameData::readConfigFile(std::string filename){
    return;
}

void gameData::readExecFile(const std::string& filename){
    int commandnum = 1;
    int msg;
    std::string lineContent;
    std::ifstream fileSaved(filename + ".cfg");
    Interpreter interpreter;

    if (fileSaved.is_open()) {
        while (getline(fileSaved, lineContent)) {
            std::cout << "\nCommand #" << commandnum << ":" << std::endl;
            std::cout << lineContent << "\n" << std::endl; // prints out everything
            if (!lineContent.empty()) {
                msg = treatCommand(lineContent,interpreter);
                std::cout << msg << std::endl;
                commandnum++;
            }
        }
        fileSaved.close();
    } else {
        std::cout << "ERROR: " << strerror(errno) << std::endl;
    }
}

bool gameData::saveCommands(std::string filename){
    std::ofstream file;
    file.open(filename + ".txt");
    for (int i = 0; i < commandHistory.size(); ++i) {
        file << commandHistory[i] << std::endl;
    }

    file.close();
    return true;
}

void gameData::saveCommsVec(std::string command){
    commandHistory.push_back(command);
}

// void createLoadedWorld(file loadedFile){
//     Island world(loadedFile.giveLines(), loadedFile.giveColumns());
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