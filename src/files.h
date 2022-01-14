#ifndef POOISLAND_FILES_H
#define POOISLAND_FILES_H

#include <iostream>
#include <fstream>
#include <string>

bool checkFiletxt(const std::string& filename);
bool checkFilecfg(const std::string& filename);

// add #include if needed
// class file{
// private:
//     std::vector<std::string> commandsHistory;
//     int dim[2];
// public:
//     void receiveDim(const int dims[2]){
//         dim[0] = dims[0];
//         dim[1] = dims[1];
//     }

//     void receiveCommand(const std::string& command){
//         commandsHistory.push_back(command);
//     }

//     int giveLines(){
//         return dim[0];
//     }

//     int giveColumns(){
//         return dim[1];
//     }

//     std::vector<std::string> getCommands();

// };

// file openFile(const std::string& filename);
// bool saveFile(const std::string& filename, const file &filereceived);
// bool saveCommands(const std::string& filename, file filereceived);

#endif //POOISLAND_FILES_H
