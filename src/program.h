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

    resourcesStr resourcesVar;

    std::vector<Island> gameVersions;
    std::vector<std::string> gameVersionsNames;
    int indexOfSaveWithName(std::string);

    // vector that contains command strings
    std::vector<std::string> commandHistory;
    double elapsed_seconds_var;
public:
    gameData();

    double & elapsed_seconds();

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
    int treatCommand(std::string& commands, Interpreter&, double);

    int saveVersion(std::string name);
    int deleteVersion(std::string name);
    int loadVersion(std::string name);
    std::string saveScreen();
};

#endif //POOISLAND_PROGRAM_H