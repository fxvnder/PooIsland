#include "buildings.h"

// ===== Class Building ===== //
std::string Building::type(){
    return type_var;
}

// ===== Class ironFarm ===== //
ironFarm::ironFarm(){
    type_var = "mnF";
}

// ===== Class coalMine ===== //
coalMine::coalMine(){
    type_var = "mnC";
}

// ===== Class electricityCentral ===== //
electricityCentral::electricityCentral(){
    type_var = "elec";
}

// ===== Class battery ===== //
battery::battery(){
    type_var = "bat";
}

// ===== Class foundry ===== //
foundry::foundry(){
    type_var = "fun";
}

// ===== Class Sarration ===== //
Sarration::Sarration(){
    type_var = "sarr";
}