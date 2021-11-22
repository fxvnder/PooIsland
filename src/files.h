#ifndef POOISLAND_FILES_H
#define POOISLAND_FILES_H

#include <vector>
#include "objects.h"

class file{
private:
    std::vector<std::string> commandsHistory;
    int dim[2];
public:
    void receiveDim(const int dims[2]){
        dim[0] = dims[0];
        dim[1] = dims[1];
    }
    void receiveCommand(const std::string& command){
        commandsHistory.push_back(command);
    }
};

bool saveFile(const std::string& filename, const file& filereceived);
bool openFile(const std::string& filename);

#endif //POOISLAND_FILES_H
