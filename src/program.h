#ifndef POOISLAND_PROGRAM_H
#define POOISLAND_PROGRAM_H

#include "island.h"
#include "files.h"
#include "interpreter.h"

#include <vector>
#include <sstream>
#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

class gameData {
private:
    Island world;
    //std::vector<std::string> resources;
    //std::vector<int> resources_quantities;

    resourcesStr resourcesVar;

    // vector that contains command strings
    std::vector<std::string> commandHistory;
    
public:
    gameData();

    std::string timeOfDay(int);

    void createNewWorld(int *dim);

    void dawn();
    void dusk();
    bool over();

    Island &island();

    std::string interpreter(int errorCode);

    // files
    void readConfigFile(const std::string filename);
    void readExecFile(std::string filename);

    // saves commands in vector
    void saveCommsVec(const std::string& command);
    // saves commands in file
    bool saveCommands(const std::string& filename);

    // manages the commands
    int treatCommand(std::string& commands, Interpreter&);
};

#endif //POOISLAND_PROGRAM_H