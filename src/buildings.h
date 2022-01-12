#ifndef POOISLAND_BUILDINGS_H
#define POOISLAND_BUILDINGS_H
#include <iostream>

class Building {
private:
protected:
    std::string type_var;
public:
    std::string type();
};

//        mnF -> Mina de ferro
//        mnC -> Mina de carvão
//        elec -> Central elétrica
//        bat -> Bateria
//        fun -> Fundição

class ironFarm : public Building{
public:
    ironFarm();
};

class coalMine : public Building{
public:
    coalMine();
};

class electricityCentral : public Building{
public:
    electricityCentral();
};

class battery : public Building{
public:
    battery();
};

class foundry : public Building{
public:
    foundry();
};

class Sarration : public Building{
public:
    Sarration();
};

#endif //POOISLAND_BUILDINGS_H
