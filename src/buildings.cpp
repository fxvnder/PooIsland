#include "island.h"
#include "buildings.h"
#include "tile.h"

// ===== Class Building ===== //
Building::Building(Tile &tile) : on(false), tile(tile) { }
std::string Building::type() {
    return type_var;
}
Building::Building(const Building &old)  // const por cópia
:   on(old.on),
    type_var(old.type_var),
    tile(tile) {} ;

Building & Building::operator=( /*const*/ Building /*&*/ old) { // idioma swap
    // este objeto old vai morrer aqui
    std::swap (on, old.on);
    std::swap (type_var, old.type_var);
    //std::swap (tile, old.tile);
    return *this; // pensar no quê que (a = b) retorna, para casos do tipo a = (b = c)
}
Building & Building::dup(Building*old, Tile & tilezz){
    on = old->on;
    type_var = old->type_var;
    tile = tilezz;

    return *this;
}

Building::~Building() {}
void Building::dusk() {}
int Building::turnOff(){
    if (on == 0) return -8;
    on = false;
    return 5;
}
int Building::turnOn(){
    if (on == 0) return -9;
    on = true;
    return 6;
}
std::string Building::upgrade(){ return "not upgradable"; };

// ===== Class ironFarm ===== //
ironFarm::ironFarm(class Tile &tile) : Building(tile) {
    type_var = "mnF";
    level = 1;
    maxiron = 100;
}
void ironFarm::dusk(){
    std::cout << "iron dusk: " <<tile.resources().iron << "  " << maxiron;
    if(tile.resources().iron <= maxiron-2){
        tile.resources().iron += 2 + level;
    }
}
std::string ironFarm::upgrade(){
    if (level < 5){
        level += 1;
        maxiron += 100;
        return "SUCCESS: upgraded!";
    } else
        return "ERROR: already at max level";
}

// ===== Class coalMine ===== //
coalMine::coalMine(class Tile &tile) : Building(tile) {
    type_var = "mnC";
}
std::string coalMine::upgrade(){ return "ERROR: not upgradable"; };

// ===== Class electricityCentral ===== //
electricityCentral::electricityCentral(class Tile &tile) : Building(tile) {
    type_var = "elec";
}
std::string electricityCentral::upgrade(){ return "ERROR: not upgradable"; };

void electricityCentral::dusk(){
    std::cout << "we got thehere \n";
    if (tile.atLeastOneWorkerOfType("oper") && tile.atLeastOneAdjacentTileOfType("flr")) {
        Tile * tileptr = tile.ptrToAdjacentTileOfType("flr");
        tileptr->resources().wood -= 1;
        tile.resources().coal += 1;
        tileptr = tile.ptrToAdjacentTileWithBuildingOfType("bat");
        if (tileptr != nullptr){
            tileptr->resources().electricity += 1;
        }
    }
}

// ===== Class battery ===== //
battery::battery(class Tile &tile) : Building(tile) {
    type_var = "bat";
}
std::string battery::upgrade(){ return "not upgradable"; };

// ===== Class foundry ===== //
//Fundição. Permite obter aço a partir de ferro e carvão. Para funcionar é necessário que a zona em que se
//encontre seja adjacente a uma zona que tenha uma mina de ferro e a uma mina de carvão ou a uma central
//elétrica (por causa do carvão). Precisa também de ter um operário na sua zona. Custa 10 €.
foundry::foundry(class Tile &tile) : Building(tile) {
    type_var = "fun";
}
std::string foundry::upgrade(){ return "not upgradable"; };

// ===== Class Sarration ===== //
sarration::sarration(class Tile &tile) : Building(tile) {
    type_var = "sarr";
}
std::string sarration::upgrade(){ return "not upgradable"; };