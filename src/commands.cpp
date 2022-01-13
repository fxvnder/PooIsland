#include <iostream>
#include <vector>
#include <algorithm>
#include "files.h"
#include "program.h"

int gameData::treatCommand(std::string& commands, Interpreter& interpreter) {

    // convert string to lowercase
    commands = strToLower(commands);
    //std::transform(commands.begin(), commands.end(), commands.begin(), ::tolower);

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

    // == <<<COMMANDS>>> ==

    // !!! GAME COMMANDS !!!

    // EXEC
    if (commandsVec[0] == "exec") { // executes saved file
        if(checkFiletxt(commandsVec[1])){
            readExecFile(commandsVec[2]);
            return 1;
        } else return -1;

    // CONS
    } else if (commandsVec[0] == "cons") { // constroi <tipo> <linha> <coluna>
        if (commandsVec.size() != 4) return -2;
        else {
            if (std::isdigit(commandsVec[2].at(0)) || std::isdigit(commandsVec[3].at(0))) {
                if (Island().isOutOfBounds(stoi(commandsVec[2]), stoi(commandsVec[3])))
                    return -3;
                else {
                    int l = stoi(commandsVec[2]) ; int c = stoi(commandsVec[2]);
                    //interpreter.overloadedMsg() = Island().cons(commandsVec).str();
                    interpreter.overloadedMsg() = Island().tile(l,c).build(commandsVec[1]);
                    return 111;
                }
            } else return -4;
        }

    // UPGRADE
    } else if (commandsVec[0] == "upgrade") { // upgrade <linha> <coluna>
        if (commandsVec.size() != 3) return -2;
        // comandos
        //interpreter.overload(Island().upgrade(commandsVec).str());
        return 111;

    // LIGA
    } else if (commandsVec[0] == "liga") { // liga <linha> <coluna>
        //liga(Island,commandsVec)
        if (commandsVec.size() != 3) return -2;
        oss << "liga " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << std::endl;
        //interpreter.overload(Island().turnOn(commandsVec).str());
        return 111;

    // DES
    } else if (commandsVec[0] == "des") { // des <linha> <coluna>
        //des(Island,commandsVec)
        if (commandsVec.size() != 3) return -2;
        oss << "desliga " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << std::endl;
        //interpreter.overload(Island().turnOff(commandsVec).str());
        return 111;

    // MOVE
    } else if (commandsVec[0] == "move") { // move <id> <linha> <coluna>
        //move(Island,commandsVec)
        if (commandsVec.size() != 4) return -2;
        oss << "liga " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << std::endl;
        //interpreter.overload(Island().move(commandsVec).str());
        return 111;

    // VENDE
    } else if (commandsVec[0] == "vende") { // vende <tipo> <quanto> ou vende <linha> <coluna>
        //vende(Island,commandsVec)
        if (commandsVec.size() != 3) return -2;
        oss << "vende " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << std::endl;
        //interpreter.overload(Island().vende(commandsVec).str());
        return 111;

    // CONT
    } else if (commandsVec[0] == "cont") { // cont <tipo>, contrata trabalhador para a area <area>
        if (commandsVec.size() != 2) return -2;
        else {
            //interpreter.overloadedMsg() = Island().cont(commandsVec).str();
            return 111;
        }

    // LIST
    } else if (commandsVec[0] == "list") { // list <linha> <coluna>, lista eventos, trabalhadores, etc.
        if (commandsVec.size() == 1) {
            interpreter.overloadedMsg() = Island().showInfoIsland();
            return 111;
        } if (commandsVec.size() != 3)
            return -2;
        if (!(std::isdigit(commandsVec[1].at(0))  && std::isdigit(commandsVec[2].at(0))))
            return -4;
        if (Island().isOutOfBounds(stoi(commandsVec[1]),stoi(commandsVec[2])))
            return -3;
        interpreter.overloadedMsg() = Island().tile(stoi(commandsVec[1]),stoi(commandsVec[2])).showInfoTile();
        return 111;

    // NEXT
    } else if (commandsVec[0] == "next") { // next
        if (commandsVec.size() != 1) return -2;
        return 0;

    // SAVECOMMANDS
    } else if (commandsVec[0] == "savecommands") { // savecommands <nome>
        if (commandsVec.size() != 2) return -2;
        //saveFile(commandsVec[1], savegame);
        if(saveCommands(commandsVec[1])) {
            return 4;
        } else return -404;

    // SAVE
    } else if (commandsVec[0] == "save") { // save <nome>
        if (commandsVec.size() != 2) return -2;
        // SAVES GAME IN MEMORY
        return -404;

    // LOAD
    } else if (commandsVec[0] == "load") { // load <nome>
        if (commandsVec.size() != 2) return -2;
        return -404;

    // APAGA
    } else if (commandsVec[0] == "apaga") { // apaga <nome>
        if (commandsVec.size() != 2) return -2;
        return -404;

    // CONFIG
    } else if (commandsVec[0] == "config") { // config <ficheiro>
        if (commandsVec.size() != 2) return -2;
        if(checkFilecfg(commandsVec[1])){
            readConfigFile(commandsVec[1]);
            return 0;
        } else return -6;

    // !!! DEBUG COMMANDS !!!

    // DEBCASH
    } else if (commandsVec[0] == "debcash") { // debcash <valor>
        if (commandsVec.size() != 2) return -2;
        return -404;

    // DEBED
    } else if (commandsVec[0] == "debed") { // debed <tipo> <linha> <coluna>
        if (commandsVec.size() != 4) return -2;
        return -404;

    // DEKILL
    } else if (commandsVec[0] == "debkill") { // dekill <id>
        if (commandsVec.size() != 2) return -2;
        return -404;

    // !!! MISC. COMMANDS !!!

    // CREDITS
    } else if (commandsVec[0] == "credits") { // credits
        if (commandsVec.size() != 1) return -2;
        return 2;

    // HELP
    } else if (commandsVec[0] == "help") { // exit <id>
        if (commandsVec.size() != 1) return -2;
        return 3;
    }

    // EXIT
    else if (commandsVec[0] == "exit") { // exit <id>
        if (commandsVec.size() != 1) return -2;
        exit(1);
    }

    return -5;
}
