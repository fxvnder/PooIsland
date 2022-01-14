#include "island.h"
#include "buildings.h"
#include "tile.h"

// ===== Class Building ===== //
Building::Building(Tile &tile) : on(false), tile(tile) { }
std::string Building::type() {
    return type_var;
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

// ===== Class ironFarm ===== //
ironFarm::ironFarm(class Tile &tile) : Building(tile) {
    type_var = "mnF";
}

// ===== Class coalMine ===== //
coalMine::coalMine(class Tile &tile) : Building(tile) {
    type_var = "mnC";
}

// ===== Class electricityCentral ===== //
electricityCentral::electricityCentral(class Tile &tile) : Building(tile) {
    type_var = "elec";
    tile.resources().money -= 15;
}
void electricityCentral::dusk(){
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

// ===== Class foundry ===== //
//Fundição. Permite obter aço a partir de ferro e carvão. Para funcionar é necessário que a zona em que se
//encontre seja adjacente a uma zona que tenha uma mina de ferro e a uma mina de carvão ou a uma central
//elétrica (por causa do carvão). Precisa também de ter um operário na sua zona. Custa 10 €.
foundry::foundry(class Tile &tile) : Building(tile) {
    type_var = "fun";
}

// ===== Class Sarration ===== //
sarration::sarration(class Tile &tile) : Building(tile) {
    type_var = "sarr";
}