#include "buildings.h"
#include "tile.h"

// ===== Class Building ===== //
Building::Building(Tile &tile) : tile(tile){
}

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
foundry::foundry(class Tile &tile) : Building(tile) {
    type_var = "fun";
}

// ===== Class Sarration ===== //
Sarration::Sarration(class Tile &tile) : Building(tile) {
    type_var = "sarr";
}