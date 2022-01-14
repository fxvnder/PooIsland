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

    // CONS
    if (commandsVec[0] == "cons") { // constroi <tipo> <linha> <coluna>
        if (commandsVec.size() != 4) return -2; // checks if too many arguments
        else {
            if (std::isdigit(commandsVec[2].at(0)) || std::isdigit(commandsVec[3].at(0))) {
                // checks if out of bounds
                if (island().isOutOfBounds(stoi(commandsVec[2]), stoi(commandsVec[3])))
                    return -3;
                else {
                    // l = lines, c = columns
                    int l = stoi(commandsVec[2]) ; int c = stoi(commandsVec[3]);
                    // sends to interpreter
                    interpreter.overloadedMsg() = island().tile(l,c).build(commandsVec[1]);
                    return 111;
                }
            } else return -4;
        }

    // UPGRADE
    } else if (commandsVec[0] == "upgrade") { // upgrade <linha> <coluna>
        if (commandsVec.size() != 3) return -2;
        // comandos
        //interpreter.overload(island().upgrade(commandsVec).str());
        return 111;


    // LIGA
    } else if (commandsVec[0] == "liga") { // des <linha> <coluna>
        if (commandsVec.size() != 3) return -2;
        if (island().isOutOfBounds(stoi(commandsVec[1]), stoi(commandsVec[2])))
            return -3;
        if (island().tile(stoi(commandsVec[1]),stoi(commandsVec[2])).building() == nullptr)
            return -7;
        return island().tile(stoi(commandsVec[1]),stoi(commandsVec[2])).building()->turnOn();

    // DES
    } else if (commandsVec[0] == "des") { // liga <linha> <coluna>
        if (commandsVec.size() != 3) return -2;
        if (island().isOutOfBounds(stoi(commandsVec[1]), stoi(commandsVec[2])))
            return -3;
        if (island().tile(stoi(commandsVec[1]),stoi(commandsVec[2])).building() == nullptr)
            return -7;
        return island().tile(stoi(commandsVec[1]),stoi(commandsVec[2])).building()->turnOff();


    // MOVE
    } else if (commandsVec[0] == "move") { // move <id> <linha> <coluna>
        //move(island,commandsVec)
        if (commandsVec.size() != 4) return -2; // checks if too many arguments
        else {
            if (std::isdigit(commandsVec[2].at(0)) || std::isdigit(commandsVec[3].at(0))) {
                // checks if out of bounds
                if (island().isOutOfBounds(stoi(commandsVec[2]), stoi(commandsVec[3])))
                    return -3;
                else {
                    // l = lines, c = columns
                    int l = stoi(commandsVec[2]) ; int c = stoi(commandsVec[3]);
                    // sends to interpreter
                    interpreter.overloadedMsg() = island().move(commandsVec[1], l, c);
                    return 111;
                }
            } else return -4;
        }
        //interpreter.overload(island().move(commandsVec).str());
        return 111;

    // VENDE
    } else if (commandsVec[0] == "vende") { // vende <tipo> <quanto> ou vende <linha> <coluna>
        //vende(island,commandsVec)
        if (commandsVec.size() != 3) return -2;
        oss << "vende " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << std::endl;
        //interpreter.overload(island().vende(commandsVec).str());
        return 111;

    // CONT
    } else if (commandsVec[0] == "cont") { // cont <tipo>, contrata trabalhador para a area <area>
        if (commandsVec.size() != 2) return -2;
        else {
            interpreter.overloadedMsg() = island().cont(commandsVec[1]);
            return 111;
        }

    // LIST
    } else if (commandsVec[0] == "list") { // list <linha> <coluna>, lista eventos, trabalhadores, etc.
        if (commandsVec.size() == 1) {
            interpreter.overloadedMsg() = island().showInfoIsland();
            return 111;
        } if (commandsVec.size() != 3)
            return -2;
        if (!(std::isdigit(commandsVec[1].at(0)) && std::isdigit(commandsVec[2].at(0))))
            return -4;
        if (island().isOutOfBounds(stoi(commandsVec[1]),stoi(commandsVec[2])))
            return -3;
        interpreter.overloadedMsg() = island().tile(stoi(commandsVec[1]),stoi(commandsVec[2])).showInfoTile();
        return 111;

    // NEXT
    } else if (commandsVec[0] == "next") { // next
        if (commandsVec.size() != 1) return -2;
        return 0;

    // MEMORY STUFF
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

    // FILES STUFF
    // EXEC
    } else if (commandsVec[0] == "exec") { // executes saved file
        if(checkFiletxt(commandsVec[1])){
            readExecFile(commandsVec[2]);
            return 1;
        } else return -1;

    // CONFIG
    } else if (commandsVec[0] == "config") { // config <ficheiro>
        if (commandsVec.size() != 2) return -2;
        if(checkFilecfg(commandsVec[1])){
            readConfigFile(commandsVec[1]);
            return 0;
        } else return -6;

    // SAVECOMMANDS
    } else if (commandsVec[0] == "savecommands") { // savecommands <nome>
        if (commandsVec.size() != 2) return -2;
        //saveFile(commandsVec[1], savegame);
        if (saveCommands(commandsVec[1])) {
            return 4;
        } else return -404;

    // !!! DEBUG COMMANDS !!!

    // DEBCASH
    } else if (commandsVec[0] == "debcash") { // debcash <valor>
        if (commandsVec.size() != 2) return -2; // checks if too many arguments
        //if ()
        island().resources().money
        return -404;


    // DEBED
    } else if (commandsVec[0] == "debed") { // debed <tipo> <linha> <coluna>
        if (commandsVec.size() != 4) return -2;
        return -404;

    // DEBKILL
    } else if (commandsVec[0] == "debkill") { // debkill <id>
        if (commandsVec.size() != 2) return -2; // checks if too many arguments

        std::ostringstream oss;
        std::stringstream workerIDstream;
        int workerIDint, l, c;

        // converts string to ostring
        workerIDstream << commandsVec[1];

        // converts ostring to int
        workerIDstream >> workerIDint;

        for (int i = 0; i < world.tiles().size() ; ++i) {
            for (int j = 0; j < world.tiles()[0].size(); ++j) {
                for (int k = 0; k < world.tiles()[i][j]->workers().size(); ++k) {
                    if(world.tiles()[i][j]->workers()[k]->giveIdentificador()[0] == workerIDint + 1) {
                        interpreter.overloadedMsg() = island().debkill(workerIDint);
                        return 111;
                    }
                }
            }
        }
        return 0;

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
