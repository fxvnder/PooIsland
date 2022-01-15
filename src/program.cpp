#include "program.h"

gameData::gameData(){ }

Island &gameData::island(){
    return world;
}

double & gameData::elapsed_seconds(){
    return elapsed_seconds_var;
}

void gameData::createNewWorld(int * dim){
    world.changeDim(dim[0], dim[1]);
    //file savegame;
    //savegame.receiveDim(dim);
    //game(savegame);
}

void gameData::dawn(){
    island().dawn();
    std::cout << "It's dawn..." << std::endl;
}

void gameData::dusk(){
    island().dusk();
    std::cout << "It's dusk..." << std::endl;
}

bool gameData::over(){
    return false;
}

// STUFF WITH FILES

void gameData::readConfigFile(const std::string filename){
    // to be done
}

void gameData::readExecFile(std::string filename){
    int commandnum = 1;
    int msg;
    std::string lineContent;
    std::ifstream fileSaved(filename + ".txt");
    Interpreter interpreter;

    if (fileSaved.is_open()) {
        while (getline(fileSaved, lineContent)) {
            std::cout << "\nCommand #" << commandnum << ":" << std::endl;
            std::cout << lineContent << "\n" << std::endl; // prints out everything
            if (!lineContent.empty()) {
                msg = treatCommand(lineContent,interpreter,0);
                std::cout << msg << std::endl;
                commandnum++;
            }
        }
        fileSaved.close();
    std::cout << "SUCCESS!" << std::endl;
    } else {
        std::cout << "ERROR: " << strerror(errno) << std::endl;
    }
}

bool gameData::saveCommands(const std::string& filename){
    std::ofstream file;
    file.open(filename + ".txt");
    for (int i = 0; i < commandHistory.size(); ++i) {
        file << commandHistory[i] << std::endl;
    }

    file.close();
    return true;
}

void gameData::saveCommsVec(const std::string& command){
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