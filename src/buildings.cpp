#include "buildings.h"
#include "tile.h"

// ===== Class Building ===== //
Building::Building(Tile &tile) : on(1), tile(tile){ }

std::string Building::type() {
    return type_var;
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
Sarration::Sarration(class Tile &tile) : Building(tile) {
    type_var = "sarr";
}