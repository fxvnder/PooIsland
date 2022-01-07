#ifndef POOISLAND_TILE_H
#define POOISLAND_TILE_H

#include <iostream>
#include <vector>
#include <random>
#include "workers.h"

class tile{
private:
    std::vector<std::string> v_types = {"pnt","dsr", "pas", "flr", "pnt", "znZ", "mnF", "mnC", "elec", "bat", "fun"};
    std::string typevar;
    std::string buildingvar;
    // miner len oper
    std::vector<worker> workers;
public:
    tile();
    std::string showInfoTile() const;
    std::string cont(const std::string& cmnd);
    std::string type() const;
    std::string& type();
    void chgType(std::string type);
    std::string building() const;
    std::vector<std::string> existingTypes() const;
    std::string cons(const std::string& command);
};

#endif //POOISLAND_TILE_H
