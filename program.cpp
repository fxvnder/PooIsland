#include <iostream>
#include <fstream>
#include "program.h"
#include "files.h"
#include "objects.h"

void run(int * dim){
    island world(dim[0], dim[1]);
    days(world);
}

void days(island& world){
    do {
        std::cout << world.showInfoIsland() << std::endl;
        dawn(world);
        plays(world);
        dusk(world);
    } while (!gameover(world));
}

void dawn(island& world){
    std::cout << "dawn" << std::endl;
}

void dusk(island& world){
    std::cout << "dusk" << std::endl;
}

bool gameover(island& world){
    return false;
}

std::string treatCommand(std::string commands, island world) {
    // manage commands
    std::vector<std::string> commandsVec;
    std::string separateWords;
    std::stringstream strStream(commands);

    // exec
    std::string fileName, lines, op;

    while (strStream >> separateWords) {
        commandsVec.push_back(separateWords);
    }

    if (commandsVec[0] == "exec"){
        std::ifstream fileSaved(commandsVec[1]);
        while (!fileSaved.eof()) {
            std::cout << lines << std::endl; // prints out everything
            if (!lines.empty()){
                op = lines;
                //treatCommand(op, world);
            }
        }
    } else if (commandsVec[0] == "save") {
        saveFile("abc");
    } else if(commandsVec[0] == "exit") {
        std::cout << "xau" << std::endl;
        exit(1);
    }
    return "error";
}

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