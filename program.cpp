#include <iostream>
#include <fstream>
#include "program.h"
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

void run(int * dim){
    island world(dim[0], dim[1]);
    days(world);
}

void days(island& world){
    do {
        cout << world.showInfoIsland() << endl;
        dawn(world);
        plays(world);
        dusk(world);
    } while (!gameover(world));
}

void dawn(island& world){
    cout << "dawn" << endl;
}

void dusk(island& world){
    cout << "dusk" << endl;
}

bool gameover(island& world){
    return false;
}
//endregion

//region Working with commands

string treatCommand(string commands) {
    // manage commands
    vector<string> commandsVec;
    string separateWords;
    stringstream strStream(commands);
    ostringstream oss;

    while (strStream >> separateWords) {
        commandsVec.push_back(separateWords); // separates the words in a vector
    }

    // COMMANDS
    if (commandsVec[0] == "exec") { // exec <nomeFicheiro>, executes saved file
        // vars TODO: Founder fix files
        string fileName, numlines, opert;
        ifstream fileSaved;

        fileSaved.open(commandsVec[1]+".cfg",std::ios::in);

        if (fileSaved.is_open()) {
            while (getline(fileSaved, numlines)) {
                cout << numlines << endl; // prints out everything
                if (!numlines.empty()) {
                    opert = numlines;
                    treatCommand(opert);
                }
            }
            fileSaved.close();
            cout << "Ficheiro carregado com sucesso!" << endl;
        } else return "error opening file";
        return "file opened";

    } else  if (commandsVec[0] == "cons") { // constroi <tipo> <linha> <coluna>
        if (commandsVec.size() != 4) return "error: Invalid number of arguments\n";
        oss << "building " << commandsVec[1] << " in X=" << commandsVec[2] << " Y=" << commandsVec[3] << endl;
        return oss.str();

    } else if (commandsVec[0] == "liga") { // liga <linha> <coluna>
        //liga(island,commandsVec)
        if (commandsVec.size() != 3) return "error: Invalid number of arguments\n";
        oss << "liga " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << endl;
        return oss.str();

    } else if (commandsVec[0] == "des") { // des <linha> <coluna>
        //des(island,commandsVec)
        if (commandsVec.size() != 3) return "error: Invalid number of arguments\n";
        oss << "desliga " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << endl;
        return oss.str();

    } else if (commandsVec[0] == "move") { // move <id> <linha> <coluna>
        //move(island,commandsVec)
        if (commandsVec.size() != 4) return "error: Invalid number of arguments\n";
        oss << "liga " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << endl;
        return oss.str();

    } else if (commandsVec[0] == "vende") { // vende <tipo> <quanto> ou vende <linha> <coluna>
        //vende(island,commandsVec)
        if (commandsVec.size() != 3) return "error: Invalid number of arguments\n";
        oss << "vende " << " in X=" << commandsVec[1] << " Y=" << commandsVec[2] << endl;
        return oss.str();

    } else if (commandsVec[0] == "cont") { // cont <tipo>, contrata trabalhador para a area <area> // TODO: VETOR TRABALHADORES!!!
        if (commandsVec.size() != 2) return "error: Invalid number of arguments\n";
        oss << "hiring worker to " << commandsVec[1] << endl;
        return oss.str();

    } else if (commandsVec[0] == "list") { // list <linha> <coluna>, lista eventos, trabalhadores, etc.
        if (commandsVec.size() != 3) return "error: Invalid number of arguments\n";
        oss << "list" << commandsVec[1] << endl;
        return oss.str();

    } else if (commandsVec[0] == "next") { // next
        if (commandsVec.size() != 1) return "error: Invalid number of arguments\n";
        return "continuing...\n";

    } else if (commandsVec[0] == "save") { // save <nome>
        if (commandsVec.size() != 2) return "error: Invalid number of arguments\n";
        saveFile("abc");
        return "file saved\n";

    } else if (commandsVec[0] == "load") { // load <nome>
        if (commandsVec.size() != 2) return "error: Invalid number of arguments\n";
        return "file loaded\n";

    } else if (commandsVec[0] == "apaga") { // apaga <nome>
        if (commandsVec.size() != 2) return "error: Invalid number of arguments\n";
        return "apagado\n";

    } else if (commandsVec[0] == "config") { // config <ficheiro>
        if (commandsVec.size() != 2) return "error: Invalid number of arguments\n";
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

    } else if (commandsVec[0] == "exit") { // exit <id>
        if (commandsVec.size() != 1) return "error: Invalid number of arguments\n";
        exit(1);
        return "exit\n";
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