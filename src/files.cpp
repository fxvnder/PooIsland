#include "files.h"

bool checkFilecfg(const std::string& filename){ // function to check if file filename exists
    std::ifstream trymefile;
    trymefile.open(filename + ".cfg");
    if(trymefile) {
        return true; // it exists. great success!
    } else {
        return false; // no file with that name was found. or... maybe error opening it.
    }
}

bool checkFiletxt(const std::string& filename){ // function to check if file filename exists
    std::ifstream trymefile;
    trymefile.open(filename + ".txt");
    if(trymefile) {
        return true; // it exists. great success!
    } else {
        return false; // no file with that name was found. or... maybe error opening it.
    }
}

// bool saveFile(const std::string& filename, const file& filereceived) {
//     // vars
//     std::ofstream saveFile;

//     // exporting to file
//     try {
//         saveFile.open(filename + ".cfg", std::ios::out | std::ios::app);
//         saveFile.write((char*)&filereceived, sizeof(filereceived));
//         saveFile.close();
//         return true;
//     } catch (const std::exception& e) {
//         std::cout << "ERROR (saving file): " << e.what() << std::endl;
//         return false;
//     }
// }

// file openFile(const std::string& filename) {
//     // vars
//     file savedfile;
//     std::ifstream openFile(filename + ".cfg");

//     // importing from file
//     openFile.read((char*)&savedfile, sizeof(savedfile));

//     return savedfile;
// }

// std::vector<std::string> file::getCommands(){
//     std::vector<std::string> commands;
//     commands.reserve(commandsHistory.size());
//     for (int i = 0; i < commandsHistory.size(); ++i) commands.push_back(commandsHistory[i]);
//     return commands;
// }