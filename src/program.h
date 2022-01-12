#ifndef POOISLAND_PROGRAM_H
#define POOISLAND_PROGRAM_H

#include "island.h"
#include "files.h"
#include "interpreter.h"
#include <vector>
#include <sstream>
#include <iostream>

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
    void createNewWorld(int *dim);
    void dawn();
    void dusk();
    bool over();
    Island &island();
    void readConfigFile(std::string filename);
    void readExecFile(const std::string& filename);
    std::string interpreter(int errorCode);

    bool saveCommands(std::string filename);

    void saveCommsVec(std::string command);
    int treatCommand(std::string& commands, Interpreter&);
};

//void createLoadedWorld(file loadedFile);

#endif //POOISLAND_PROGRAM_H