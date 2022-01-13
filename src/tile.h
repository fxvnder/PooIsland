#ifndef POOISLAND_TILE_H
#define POOISLAND_TILE_H

#include <iostream>
#include <vector>
#include <random>
#include "workers.h"
#include "buildings.h"

class Island;

class Tile{
private:
    std::vector<std::string> v_buildings;
    Building* building_class;
    int coords[2];
    // miner len oper
    std::vector<Worker*> workers;
protected: // protected so the derivative classes can access it
    std::string typevar;
    Island & island_var;
public:
    Tile(Island & island, int l, int c);
    std::string showInfoTile() const;
    std::string cont(const std::string& cmnd);
    std::string type() const;
    std::string& type();
    std::string building();
    std::vector<std::string> existingTypes() const;
    std::string cons(const std::string& command);
    Island& island();
    std::vector<Tile> adjacentZones();
    std::string build(std::string&); //reference to be more optimized
private:
    Building* whichBuilding(std::string command);
};

//        pnt –> Montanha
//        dsr -> Deserto
//        pas -> Pastagem
//        flr -> Floresta
//        pnt -> Pântano
//        znZ -> ZonaX

class mountain : public Tile{
public:
    mountain(Island & island, int l, int c);
};

class desert : public Tile {
public:
    desert(Island &island, int l, int c);

};

class pasture : public Tile {
private:
public:
    pasture(Island &island, int l, int c);
};

class forest : public Tile{
private:
    int num_trees; // random 20 to 40 in the beginning, MAX: 100
public:
    forest(Island &island, int l, int c);
    int trees();
};

class swamp : public Tile {
private:
    bool hasShrek = true;
public:
    swamp(Island &island, int l, int c);
};

class zoneX : public Tile{
private:
public:
    zoneX(Island &island, int l, int c);
};



#endif //POOISLAND_TILE_H
