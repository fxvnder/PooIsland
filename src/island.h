#ifndef POOISLAND_ISLAND_H
#define POOISLAND_ISLAND_H

#include <iostream>
#include <vector>

#include "files.h"
#include "tile.h"
#include "utils.h"
#include "vector.h"
#include "resources.h"

class Island {
private:
    poo::vector<poo::vector<Tile*>> vecvec;
    //syntax for arr[l][c] will be arr[l*sizeY+c];
    std::vector<std::string> tile_types = {"pnt", "dsr", "pas", "flr", "pnt", "znZ"};
    // montanha, deserto, pastagem, floresta, pantano, zonaX

    resourcesStr resourcesVar;
public:
    Island(int l=0, int c=0);
    std::string showSimpleIsland() const;
    std::string showInfoIsland() const;
    void changeDim(int l, int c);
    Tile &tile(int l, int c);
    bool isOutOfBounds(int l, int c) const;
    bool existsInIsland(const std::string& type);
    Tile* randomTile(int l, int c);
    void dawn();
    void dusk();
    resourcesStr & resources();
    std::string cont(const std::string&  workertype);
};

#endif //POOISLAND_ISLAND_H
