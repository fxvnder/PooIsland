#ifndef POOISLAND_TILE_H
#define POOISLAND_TILE_H

#include <iostream>
#include <vector>
#include <random>
#include "workers.h"
#include "buildings.h"

class Island;

class tile{
private:
    std::vector<std::string> v_buildings;
    Building* building_class;
    int coords[2];
    // miner len oper
    std::vector<worker*> workers;
protected: // protected so the derivative classes can access it
    std::string typevar;
    Island & island;
public:
    tile(Island & island, int l, int c);
    std::string showInfoTile() const;
    std::string cont(const std::string& cmnd);
    std::string type() const;
    std::string& type();
    std::string building();
    std::vector<std::string> existingTypes() const;
    std::string cons(const std::string& command);

private:
    Building* whichBuilding(std::string command);
};

//        pnt –> Montanha
//        dsr -> Deserto
//        pas -> Pastagem
//        flr -> Floresta
//        pnt -> Pântano
//        znZ -> ZonaX

class mountain : public tile{
public:
    mountain(Island & island, int l, int c);
};

class desert : public tile {
public:
    desert(Island &island, int l, int c);

};

class pasture : public tile {
private:
public:
    pasture(Island &island, int l, int c);
};

class forest : public tile{
private:
    int num_trees; // random 20 to 40 in the beginning, MAX: 100
public:
    forest(Island &island, int l, int c);
    int trees();
};

class swamp : public tile {
private:
    bool hasShrek = true;
public:
    swamp(Island &island, int l, int c);
};

class zoneX : public tile{
private:
public:
    zoneX(Island &island, int l, int c);
};



#endif //POOISLAND_TILE_H
