#ifndef POOISLAND_BUILDINGS_H
#define POOISLAND_BUILDINGS_H
#include <iostream>
#include <vector>

class Tile;

class Building {
private:
protected:
    std::string type_var;
    Tile & tile;
public:
    std::string type();
    Building(class Tile & tile);
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
};

class battery : public Building{
public:
    battery(class Tile &tile);
};

class foundry : public Building{
public:
    foundry(class Tile &tile);
};

class Sarration : public Building{
public:
    Sarration(class Tile &tile);
};

#endif //POOISLAND_BUILDINGS_H
