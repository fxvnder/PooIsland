#include <iostream>
#include <fstream>
#include "program.h"
#include "files.h"
#include "objects.h"

//region Working with the island
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
//endregion

//region Working with commands

std::string treatCommand(std::string commands) {
    // manage commands
    std::vector<std::string> commandsVec;
    std::string separateWords;
    std::stringstream strStream(commands);

    while (strStream >> separateWords) {
        commandsVec.push_back(separateWords); // separates the words in a vector
    }

    // COMMANDS

    if (commandsVec[0] == "exec") { // executes saved file
        // vars TODO: WHY IS THIS NOT WORKING WHAT THE HELL
        std::string fileName, numlines, opert;
        std::ifstream fileSaved(commandsVec[1] + ".cfg");

        if (fileSaved.is_open()) {
            while (getline(fileSaved, numlines)) {
                std::cout << numlines << std::endl; // prints out everything
                if (!numlines.empty()) {
                    opert = numlines;
                    treatCommand(opert);
                }
            }
            fileSaved.close();
            std::cout << "Ficheiro carregado com sucesso!" << std::endl;
        } else return "error opening file";
        return "file opened";
    } else if (commandsVec[0] == "cons") { // constroi <tipo> <linha> <coluna>
        // TODO: meter isto a funcionar no vetor!!! X/Y NAO PODE SER MAIOR QUE O TAMANHO DO VETOR (resolve-se com um if simples)! Also protecting it from sigseg, of course.
        std::cout << "building " << commandsVec[1] << " in X=" << commandsVec[2] << " Y=" << commandsVec[3] << std::endl;
        return "built";
    } else if (commandsVec[0] == "cont") { // contrata trabalhador para a area <area> // TODO: VETOR TRABALHADORES!!!
        std::cout << "hiring worker to " << commandsVec[1] << std::endl;
        return "hired";
    } else if (commandsVec[0] == "list") { // lista eventos, trabalhadores, etc.

        return "list";
    } else if (commandsVec[0] == "save") {
        saveFile("abc");
        return "file saved";
    } else if(commandsVec[0] == "exit") {
        std::cout << "xau" << std::endl;
        exit(1);
    }
    return "error";
}

//endregion

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