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
    island world;
    //std::vector<std::string> resources;
    //std::vector<int> resources_quantities;

    int iron; // Ferro
    int steel_bar; // Barra de aço
    int coal; // Carvão
    int wood; // Madeira
    int wood_plaques; // Vigas de Madeira
    int resources; // Eletricidade

    // vector that contains command strings
    std::vector<std::string> commandHistory;
    
public:
    gameData();
    void createNewWorld(int *dim);
    void dawn();
    void dusk();
    bool over();
    island &Island();
    void readConfigFile(std::string filename);
    void readExecFile(const std::string& filename);
    std::string interpreter(int errorCode);

    bool saveCommands(std::string filename);

    void saveCommsVec(std::string command);
    int treatCommand(std::string& commands, Interpreter&);
};

//void createLoadedWorld(file loadedFile);

#endif //POOISLAND_PROGRAM_H