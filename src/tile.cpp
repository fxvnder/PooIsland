#include "tile.h"
#include "program.h"
#include "utils.h"
#include <iostream>
#include <vector>
#include <random>

tile::tile() : buildingvar(""), workers() {
    typevar = v_types[random(0,v_types.size() - 1)];
    // access the island here
}
std::string tile::showInfoTile() const {
    std::ostringstream oss;
    std::string tmp;

    oss << "┌────┐" << std::endl;

    oss << "|" << typevar;
    for (int i = typevar.size(); i < TILEDISPSIZE; ++i)
        oss << " ";
    oss <<      "|" << std::endl;

    oss << "|" << buildingvar;
    for (int i = buildingvar.size(); i < TILEDISPSIZE; ++i)
        oss << " ";
    oss <<      "|" << std::endl;
    oss << "└────┘" << std::endl;

    return oss.str();
}
std::string tile::type() const{
    return typevar;
}
std::string& tile::type(){
    return typevar;
}
void tile::chgType(std::string type){
    typevar = type;
}

std::vector<std::string> tile::existingTypes() const {
    return v_types;
};

std::string tile::building() const{
    return buildingvar;
}

std::string tile::cons(const std::string& command) {
    std::vector<std::string> v_buildings = {"minaf", "minac", "central", "bat", "fund", "edx"};
    std::ostringstream oss;
    for (int i = 0; i < v_buildings.size(); ++i) {
        if (command == v_buildings[i]){
            if (!buildingvar.empty()) {
                oss << "There's a " << buildingvar << " here already";
                return oss.str();
            }
            buildingvar = command;
            return "";
        }
    }
    oss << "Wrong specified type, the existing types of buildings are: ";
    for (const std::string& str : v_buildings)
        oss << str << ' ';
    return oss.str();
}

std::string tile::cont(const std::string& command){
    std::ostringstream oss;
    std::vector<std::string> v_types = {"miner", "len", "oper"};
    if (typevar != "pas")
        return "Can only do this for tiles of type pas";

    for (int i = 0; i < v_types.size(); ++i) {
        if (command == v_types[i]){
            //++workers[i];

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