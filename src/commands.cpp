#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cstring>

#include "files.h"
#include "commands.h"
#include "interface.h"

std::string treatCommand(std::string& commands, island& world, file& savegame) {
    // vars to manage commands
    std::vector<std::string> commandsVec;
    std::string separateWords;

    // Convert String to lowercase
    std::transform(commands.begin(), commands.end(), commands.begin(), ::tolower);

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
        int commandnum = 1;
        std::string lineContent;
        std::ifstream fileSaved(commandsVec[1] + ".cfg");
        std::string msg;

        if (fileSaved.is_open()) {
            while (getline(fileSaved, lineContent)) {
                std::cout << "\nCommand #" << commandnum << ":" << std::endl;
                std::cout << lineContent << "\n" << std::endl; // prints out everything
                if (!lineContent.empty()) {
                    msg = treatCommand(lineContent, world, savegame);
                    std::cout << msg << std::endl;
                    commandnum++;
                }
            }
            fileSaved.close();
        } else {
            std::cout << "ERROR: " << strerror(errno) << std::endl;
            return "Error opening file!";
        }
        savegame.receiveCommand(commands);
        return "File opened with success!";

    } else if (commandsVec[0] == "cons") { // constroi <tipo> <linha> <coluna>
        if (commandsVec.size() != 4) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        else {
            savegame.receiveCommand(commands);
            if (std::isdigit(commandsVec[2].at(0)) || std::isdigit(commandsVec[3].at(0))) {
                if (world.isOutOfBounds(stoi(commandsVec[2]), stoi(commandsVec[3])))
                    return "Target zone coordinates fall outside the island!";
                else
                    return world.cons(commandsVec).str();
            } else return "Expected digits";
        }

    } else if (commandsVec[0] == "liga") { // liga <linha> <coluna>
        //liga(island,commandsVec)
        if (commandsVec.size() != 3) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        oss << "liga " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << std::endl;
        savegame.receiveCommand(commands);
        return oss.str();

    } else if (commandsVec[0] == "des") { // des <linha> <coluna>
        //des(island,commandsVec)
        if (commandsVec.size() != 3) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        oss << "desliga " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << std::endl;
        savegame.receiveCommand(commands);
        return oss.str();

    } else if (commandsVec[0] == "move") { // move <id> <linha> <coluna>
        //move(island,commandsVec)
        if (commandsVec.size() != 4) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        oss << "liga " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << std::endl;
        savegame.receiveCommand(commands);
        return oss.str();

    } else if (commandsVec[0] == "vende") { // vende <tipo> <quanto> ou vende <linha> <coluna>
        //vende(island,commandsVec)
        if (commandsVec.size() != 3) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        oss << "vende " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << std::endl;
        savegame.receiveCommand(commands);
        return oss.str();

    } else if (commandsVec[0] == "cont") { // cont <tipo>, contrata trabalhador para a area <area>
        if (commandsVec.size() != 2) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        else {
            //oss << "hiring worker to " << commandsVec[1] << std::endl;
            savegame.receiveCommand(commands);
            return world.cont(commandsVec).str();
        }

    } else if (commandsVec[0] == "list") { // list <linha> <coluna>, lista eventos, trabalhadores, etc.
        if (commandsVec.size() == 1)
            return world.showInfoIsland();
        if (commandsVec.size() != 3)
            return "ERROR: Invalid number of arguments, usage: list <linha> <coluna> or simply list\n";
        if (!(std::isdigit(stoi(commandsVec[1]) ) && std::isdigit(stoi(commandsVec[2]) )))
            return "Expected digits";
        if (world.isOutOfBounds(stoi(commandsVec[1]),stoi(commandsVec[2])))
            return "Target zone coordinates fall outside the island!";
        return world.getTile(stoi(commandsVec[1]),stoi(commandsVec[2])).showInfoTile();

    } else if (commandsVec[0] == "next") { // next
        if (commandsVec.size() != 1) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        savegame.receiveCommand(commands);
        return "Continuing...\n";

    } else if (commandsVec[0] == "save") { // save <nome>
        if (commandsVec.size() != 2) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        //saveFile(commandsVec[1], savegame);
        saveCommands(commandsVec[1], savegame);
        return "file saved\n";

    } else if (commandsVec[0] == "load") { // load <nome>
        if (commandsVec.size() != 2) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        return "file loaded\n";

    } else if (commandsVec[0] == "apaga") { // apaga <nome>
        if (commandsVec.size() != 2) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        savegame.receiveCommand(commands);
        return "apagado\n";

    } else if (commandsVec[0] == "config") { // config <ficheiro>
        if (commandsVec.size() != 2) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        savegame.receiveCommand(commands);
        return "config file loaded\n";

    } else if (commandsVec[0] == "debcash") { // debcash <valor>
        if (commandsVec.size() != 2) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        return "debcash\n";

    } else if (commandsVec[0] == "debed") { // debed <tipo> <linha> <coluna>
        if (commandsVec.size() != 4) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        return "debed\n";

    } else if (commandsVec[0] == "debkill") { // dekill <id>
        if (commandsVec.size() != 2) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        return "debkill\n";

    } else if (commandsVec[0] == "credits") { // credits <id>
        if (commandsVec.size() != 1) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        showCredits();
        return "";

    } else if (commandsVec[0] == "help") { // exit <id>
        if (commandsVec.size() != 1) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        return helpMe();
    }
    else if (commandsVec[0] == "exit") { // exit <id>
        if (commandsVec.size() != 1) return "ERROR: Invalid number of arguments. Use \"help\" for help.\n";
        exit(1);
    }

    return "Malformed command, try again\n";
}