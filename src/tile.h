#ifndef POOISLAND_TILE_H
#define POOISLAND_TILE_H

#include <iostream>
#include <vector>
#include <random>
#include "workers.h"
#include "buildings.h"
#include "resources.h"

class Island;

class Tile{
private:
    std::vector<std::string> v_buildings;
    int coords[2];
    resourcesStr resources_var;
    // miner len oper
protected: // protected so the derivative classes can access it
    std::string typevar;
    Island & island_var;
    Building* building_class;
    std::vector<Worker*> workersVec;
public:
    // construidor
    Tile(Island & island, int l, int c);

    // aceder ao island
    Island& island();
    Island& island() const;

    // vetor dos trabalhadores
    std::vector<Worker*>& workers();

    // DISPLAY FUNCS
    std::string& type();
    std::string buildingStr();
    Building* building();
    std::string showInfoTile() const;
    std::string type() const;

    // commands
    std::vector<std::string> existingTypes() const;
    std::string cont(const std::string& cmnd);
    std::string debkill(int workerID);

    std::vector<Tile> adjacentZones();
    std::string build(std::string&); //reference to be more optimized
    bool atLeastOneWorkerOfType(const std::string&) const;
    bool atLeastOneAdjacentTileOfType(const std::string&) const;
    Tile* ptrToAdjacentTileOfType(const std::string&) const;
    Tile* ptrToAdjacentTileWithBuildingOfType(const std::string&) const;
    resourcesStr& resources();
    virtual void dawn();
    virtual ~Tile();
private:
    Building* whichBuilding(std::string command);
};

//        mnt –> Montanha
//        dsr -> Deserto
//        pas -> Pastagem
//        flr -> Floresta
//        pnt -> Pântano
//        znZ -> ZonaX

class mountain : public Tile{
public:
    mountain(Island & island, int l, int c);
    void dawn() override;
};

class desert : public Tile {
public:
    desert(Island &island, int l, int c);
    void dawn() override;
};

class pasture : public Tile {
private:
public:
    pasture(Island &island, int l, int c);
    void dawn() override;
};

class forest : public Tile{
private:
    int num_trees; // random 20 to 40 in the beginning, MAX: 100
public:
    forest(Island &island, int l, int c);
    void dawn() override;
    int trees() const;
};

class swamp : public Tile {
private:
    int daysSinceBuilding;
public:
    swamp(Island &island, int l, int c);
    void dawn() override;
};

class zoneX : public Tile{
private:
public:
    zoneX(Island &island, int l, int c);
    void dawn() override;
};



#endif //POOISLAND_TILE_H
