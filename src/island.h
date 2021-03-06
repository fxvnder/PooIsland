#ifndef POOISLAND_ISLAND_H
#define POOISLAND_ISLAND_H

#include <iostream>
#include <vector>
#include <algorithm>

#include "files.h"
#include "tile.h"
#include "utils.h"
#include "vector.h"
#include "resources.h"
#include "memory"

class Island {
private:
    std::string timeOfDay(int);
    // poo::vector<poo::vector<std::unique_ptr<Tile>>> vecvec; // vector of vectors that have the tiles
    poo::vector<poo::vector<Tile*>> vecvec; // vector of vectors that have the tiles
    std::vector<std::string> tile_types = {"mnt", "dsr", "pas", "flr", "pnt", "znZ"};
    // montanha, deserto, pastagem, floresta, pantano, zonaX
    resourcesStr resourcesVar;

    int roundNum, playerNum;
public:
    Island(int l=0, int c=0); // construtor
    Island(const Island &old); // copy const
    ~Island(); // destructor

    std::string showSimpleIsland() const;
    std::string showInfoIsland(double time);
    void updateGlobalResources();

    void changeDim(int l, int c);
    Tile &tile(int l, int c);
    bool isOutOfBounds(int l, int c) const;
    bool existsInIsland(const std::string& type);
    Tile* randomTile(int l, int c);
    Tile* theRightTileDup(Tile,int,int);

    // management rounds
    void incRound();
    int day() const;
    int & day();

    // management players
    int& workerIDCounter();
    const int& workerIDCounter() const;
    std::vector<int> workerNums();

    void dawn();
    void dusk();

    //resources
    resourcesStr & resources();

    // comms
    std::string cont(const std::string& workertype);
    std::string move(std::string& workerID, int l, int c);
    std::string debkill(int workerID, bool quit);
    std::string vende(const std::string& input1, const std::string& input2);

    // tiles
    poo::vector<poo::vector<Tile*>> &tiles();
};

#endif //POOISLAND_ISLAND_H
