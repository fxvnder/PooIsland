#ifndef POOISLAND_ISLAND_H
#define POOISLAND_ISLAND_H

#include <iostream>
#include <vector>

#include "files.h"
#include "tile.h"
#include "utils.h"
#include "vector.h"

struct resourcesStr {
    int iron_var; // Ferro
    int steel_bar_var; // Barra de aço
    int coal_var; // Carvão
    int wood_var; // Madeira
    int wood_plaques_var; // Vigas de Madeira
    int electricity_var; // Eletricidade
};

class Island {
private:
    int lines = 0, columns = 0;
    //syntax for arr[l][c] will be arr[l*sizeY+c];
    poo::vector<poo::vector<Tile*>> vecvec{};
    std::vector<std::string> tile_types = {"pnt","dsr", "pas", "flr", "pnt", "znZ"};

    resourcesStr resourcesVar;
public:
    Island(int l=0, int c=0);
    std::string showSimpleIsland() const;
    std::string showInfoIsland() const;
    void changeDim(int l, int c);
    Tile &tile(int l, int c);
    std::ostringstream cont(std::vector<std::string> commandsVec);
    std::ostringstream cons(std::vector<std::string> commandsVec);
    bool isOutOfBounds(int l, int c) const;
    bool existsInIsland(const std::string type);
    Tile* randomTile(int l, int c);
    void dawn();
    void dusk();
};

#endif //POOISLAND_ISLAND_H
