#ifndef POOISLAND_TILE_H
#define POOISLAND_TILE_H

#include <iostream>
#include <vector>
#include <random>

class tile{
private:
    std::string type;
    std::string building;
    // miner len oper
    int workers[3];
public:
    tile();
    std::string showInfoTile() const;
    std::string cont(const std::string& cmnd);
    std::string getType();
    std::string cons(const std::string& command);
    // friend std::ostream& operator<<(std::ostream& os, const tile& recievedTile);
};

#endif //POOISLAND_TILE_H
