#include "tile.h"
#include "program.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <random>

tile::tile() : building_class(nullptr), workers() {
    v_buildings.push_back("mnF");
    v_buildings.push_back("mnC");
    v_buildings.push_back("elec");
    v_buildings.push_back("bat");
    v_buildings.push_back("fun");
    v_buildings.push_back("sarr");
    //typevar = v_types[random(0,v_types.size() - 1)];
    // access the island here
}
std::string tile::showInfoTile() const {
    std::ostringstream oss;
    std::string tmp;

    std::string building_type;
    if (building_class == nullptr) {
        oss << "ERROR:" << std::endl;
        building_type = "";
    } else {
        oss << "ERROR:" << std::endl;
        building_type = building_class->type();
    }
    oss << "SUCCESS:" << std::endl;

    oss << "┌";
    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
    oss << "┐" << std::endl;

    oss << "|" << typevar;
    for (int i = typevar.size(); i < TILEDISPSIZE; ++i)
        oss << " ";
    oss <<      "|" << std::endl;

    oss << "|" << building_type;
    for (int i = building_type.size(); i < TILEDISPSIZE; ++i)
        oss << " ";
    oss <<      "|" << std::endl;

    oss << "└";
    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
    oss << "┘" << std::endl;

    return oss.str();
}
std::string tile::type() const{
    return typevar;
}
std::string& tile::type(){
    return typevar;
}

std::string tile::building(){
    //std::cout << building_class->type() << " | " << building_str << std::endl;
    if (building_class == nullptr) return "";
    return building_class->type();
}

std::string tile::cons(const std::string& command) {
    std::ostringstream oss;
    for (int i = 0; i < v_buildings.size(); ++i) {
        if (command == strToLower(v_buildings[i])){
            if (building_class != nullptr) {
                oss << "There's a " << command << " here already";
                return oss.str();
            }
            building_class = whichBuilding(v_buildings[i]);
            return "";
        }
    }
    oss << "Wrong specified type, the existing types of buildings are: ";
    for (const std::string& str : v_buildings)
        oss << str << ' ';
    return oss.str();
}

Building* tile::whichBuilding(std::string building){
    Building* p;
    
    if (building == "mnF"){ // IRonFarm
        p = new ironFarm;
    } else if (building == "mnC"){ //coalMine
        p = new coalMine;
    } else if (building == "elec"){ //electricityCentral
        p = new electricityCentral;
    } else if (building == "bat"){ //battery
        p = new battery;
    } else if (building == "fun"){ //foundry (fundição)
        p = new foundry;
    } else if (building == "sarr"){ //Sarration
        p = new Sarration;
    } else {
        std::cout << "Error generating building" << std::endl;
    }
    return p;
}

std::string tile::cont(const std::string& command){
    std::ostringstream oss;
    std::vector<std::string> v_types = {"miner", "len", "oper"};
    if (typevar != "pas")
        return "Can only do this for tiles of type pas";

    for (int i = 0; i < v_types.size(); ++i) {
        if (command == v_types[i]){

            switch (i) {
                case 0: //miner
                    workers.push_back(new miner);
                    break;
                case 1: //len
                    workers.push_back(new lumberjack);
                    break;
                case 2: //oper
                    workers.push_back(new operative);
                    break;
                default:
                    std::cout << "error, no worker type" << std::endl;
            }

            return "";
        }
    }
    oss << "Type of worker doesn't exist, the existing types are: ";
    for (const std::string& str : v_types){
        oss << str << ' ';
    }
    oss << std::endl;
    return oss.str();
}

// ===== Class mountain ===== //
mountain::mountain() {
    typevar = "pnt";
}

// ===== Class desert ===== //
desert::desert(){
    typevar = "dsr";

}

// ===== Class pasture ===== //
pasture::pasture(){
    typevar = "pas";
}

// ===== Class forest ===== //
forest::forest() : num_trees(0){
    typevar = "flr";
}
int forest::trees() {
    return num_trees;
}

// ===== Class swamp ===== //
swamp::swamp(){
    typevar = "pnt";
}

// ===== Class zonaX ===== //
zoneX::zoneX(){
    typevar = "znZ";
}