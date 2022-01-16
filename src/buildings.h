#ifndef POOISLAND_BUILDINGS_H
#define POOISLAND_BUILDINGS_H

#include <iostream>
#include <vector>

class Tile;

class Building {
private:
protected:
    bool on; // 1 - on | 0 - off
    std::string type_var;
    Tile & tile;
public:
    std::string type();
    int turnOff();
    int turnOn();
    Building(class Tile & tile);
    virtual void dusk();
    virtual ~Building();
    Building(const Building &old); // const por cópia
    Building & operator=(Building old);
    Building & dup(Building *old, Tile & tile);
};


//        mnF -> Mina de ferro
//        mnC -> Mina de carvão
//        elec -> Central elétrica
//        bat -> Bateria
//        fun -> Fundição

class ironFarm : public Building{
public:
    ironFarm(class Tile &tile);
};

class coalMine : public Building{
public:
    coalMine(class Tile &tile);
};

class electricityCentral : public Building{
public:
    electricityCentral(class Tile &tile);
    virtual void dusk() override;
};

class battery : public Building{
public:
    battery(class Tile &tile);
};

class foundry : public Building{
public:
    foundry(class Tile &tile);
};

class sarration : public Building{
public:
    sarration(class Tile &tile);
};

#endif //POOISLAND_BUILDINGS_H
