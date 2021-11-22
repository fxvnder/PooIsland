#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "program.h"
#include "interface.h"
#include "files.h"
#include "objects.h"

using std::cout;
using std::endl;
using std::string;
using std::stringstream;
using std::vector;
using std::ifstream;
using std::ostringstream;

//region Working with the island

void days(island& world){
    do {
        cout << world.showInfoIsland() << endl;
        dawn(world);
        plays(world);
        dusk(world);
    } while (!gameover(world));
}

void dawn(island& world){
    cout << "It's dawn..." << endl;
}

void dusk(island& world){
    cout << "It's dusk..." << endl;
}

bool gameover(island& world){
    return false;
}
//endregion

//region Working with commands

string treatCommand(const string& commands, island world) {
    // vars to manage commands
    std::vector<std::string> commandsVec;
    std::string separateWords;
    std::stringstream strStream(commands);

    // splitting "commands" into separate words
    while (strStream >> separateWords) {
        commandsVec.push_back(separateWords); // separates the words in a vector
    }

    // misc vars
    std::ostringstream oss;

    // COMMANDS

    if (commandsVec[0] == "exec") { // executes saved file
        // vars
        std::string lineContent;
        std::ifstream fileSaved(commandsVec[1] + ".cfg");

        if (fileSaved.is_open()) {
            while (getline(fileSaved, lineContent)) {
                std::cout << lineContent << std::endl; // prints out everything
                if (!lineContent.empty()) {
                    treatCommand(lineContent, world);
                }
            }
            fileSaved.close();
        } else {
            std::cout << "ERROR: " << strerror(errno) << endl;
            return "Error opening file!";
        }
        commandsHistory.push_back(commands);
        return "File opened with success!";

    } else if (commandsVec[0] == "cons") { // constroi <tipo> <linha> <coluna>
        if (commandsVec.size() != 4) return "error: Invalid number of arguments\n";
        else {
            commandsHistory.push_back(commands);
            return world.cons(commandsVec, world).str();
        }

    } else if (commandsVec[0] == "liga") { // liga <linha> <coluna>
        //liga(island,commandsVec)
        if (commandsVec.size() != 3) return "error: Invalid number of arguments\n";
        oss << "liga " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << endl;
        commandsHistory.push_back(commands);
        return oss.str();

    } else if (commandsVec[0] == "des") { // des <linha> <coluna>
        //des(island,commandsVec)
        if (commandsVec.size() != 3) return "error: Invalid number of arguments\n";
        oss << "desliga " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << endl;
        commandsHistory.push_back(commands);
        return oss.str();

    } else if (commandsVec[0] == "move") { // move <id> <linha> <coluna>
        //move(island,commandsVec)
        if (commandsVec.size() != 4) return "error: Invalid number of arguments\n";
        oss << "liga " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << endl;
        commandsHistory.push_back(commands);
        return oss.str();

    } else if (commandsVec[0] == "vende") { // vende <tipo> <quanto> ou vende <linha> <coluna>
        //vende(island,commandsVec)
        if (commandsVec.size() != 3) return "error: Invalid number of arguments\n";
        oss << "vende " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << endl;
        commandsHistory.push_back(commands);
        return oss.str();

    } else if (commandsVec[0] == "cont") { // cont <tipo>, contrata trabalhador para a area <area> // TODO: VETOR TRABALHADORES!!!
        if (commandsVec.size() != 2) return "error: Invalid number of arguments\n";
        oss << "hiring worker to " << commandsVec[1] << endl;
        commandsHistory.push_back(commands);
        return oss.str();

    } else if (commandsVec[0] == "list") { // list <linha> <coluna>, lista eventos, trabalhadores, etc.
        if (commandsVec.size() != 3) return "error: Invalid number of arguments\n";
        oss << "list" << commandsVec[1] << endl;
        return oss.str();

    } else if (commandsVec[0] == "next") { // next
        if (commandsVec.size() != 1) return "error: Invalid number of arguments\n";
        commandsHistory.push_back(commands);
        return "Continuing...\n";

    } else if (commandsVec[0] == "save") { // save <nome>
        if (commandsVec.size() != 2) return "error: Invalid number of arguments\n";
        saveFile(commandsVec[1], commandsHistory);
        return "file saved\n";

    } else if (commandsVec[0] == "load") { // load <nome>
        if (commandsVec.size() != 2) return "error: Invalid number of arguments\n";
        return "file loaded\n";

    } else if (commandsVec[0] == "apaga") { // apaga <nome>
        if (commandsVec.size() != 2) return "error: Invalid number of arguments\n";
        commandsHistory.push_back(commands);
        return "apagado\n";

    } else if (commandsVec[0] == "config") { // config <ficheiro>
        if (commandsVec.size() != 2) return "error: Invalid number of arguments\n";
        commandsHistory.push_back(commands);
        return "config file loaded\n";

    } else if (commandsVec[0] == "debcash") { // debcash <valor>
        if (commandsVec.size() != 2) return "error: Invalid number of arguments\n";
        return "debcash\n";

    } else if (commandsVec[0] == "debed") { // debed <tipo> <linha> <coluna>
        if (commandsVec.size() != 4) return "error: Invalid number of arguments\n";
        return "debed\n";

    } else if (commandsVec[0] == "debkill") { // dekill <id>
        if (commandsVec.size() != 2) return "error: Invalid number of arguments\n";
        return "debkill\n";

    } else if (commandsVec[0] == "credits") { // credits <id>
        if (commandsVec.size() != 1) return "error: Invalid number of arguments\n";
        showCredits();
        return "";

    } else if (commandsVec[0] == "help") { // exit <id>
        showCredits();
        // EXPLAIN THE GAME, BASICALLY
        return "";
    }
    else if (commandsVec[0] == "exit") { // exit <id>
        if (commandsVec.size() != 1) return "error: Invalid number of arguments\n";
        exit(1);
    }

    return "Malformed command, try again\n";
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