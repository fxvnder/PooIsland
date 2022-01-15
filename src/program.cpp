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

int gameData::saveVersion(std::string name){
    gameVersions.push_back(world);
    gameVersionsNames.push_back(name);
    return 7;
}

int gameData::deleteVersion(std::string name){
    int i = indexOfSaveWithName(name);
    if (i < 0) return i;
    gameVersions.erase(gameVersions.begin()+i);
    gameVersionsNames.erase(gameVersionsNames.begin()+i);
    return 8;
}

int gameData::loadVersion(std::string name){
    int i = indexOfSaveWithName(name);
    if (i < 0) return i;
    world = gameVersions[i];
    return 9;
}

std::string gameData::saveScreen(){
    std::ostringstream oss;
    oss << "SUCCESS:" << std::endl;
    for (std::string s : gameVersionsNames) {
        oss << s << std::endl;
    }
    return oss.str();
}

int gameData::indexOfSaveWithName(std::string name) {
    int k = 0;
    bool found = 0;
    for (k = 0; k < gameVersionsNames.size(); ++k) {
        if (gameVersionsNames[k] == name) {
            found = 1;
            break;
        }
    }
    if (found == 1)
        return k;
    else
        return -12;
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