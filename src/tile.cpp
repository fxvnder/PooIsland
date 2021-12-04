#include "tile.h"
#include "program.h"
#include <iostream>
#include <vector>
#include <random>

tile::tile() : building(""), workers() {
    std::vector<std::string> v_types = {"pnt ","dsr ", "pas ", "flr ", "pnt ", "znZ ", "mnF ", "mnC ", "elec", "bat ", "fun "};
    type = v_types[random(0,v_types.size() - 1)];
    // access the island here
}
std::string tile::showInfoTile() const {
    std::ostringstream oss;
    std::string tmp;
    oss << type;
    if (building.empty())
        oss << "     ";
    else{
        tmp += building;
        while (tmp.size() != 5){
            tmp += " ";
        }
        oss << tmp;
    }
    oss << "> " << workers[0] << '|' << workers[1] << '|' << workers[2];
    return oss.str();
}
std::string tile::getType(){
    return type;
}
std::string tile::cons(const std::string& command) {
    std::vector<std::string> v_buildings = {"minaf", "minac", "central", "bat", "fund", "edx"};
    // TODO: imprimir como {"minaf", "minac", "cntrl", " bat ", " fund", " edx "}
    std::ostringstream oss;
    for (int i = 0; i < v_buildings.size(); ++i) {
        if (command == v_buildings[i]){
            if (!(building.empty())) {
                oss << "There's a " << building << " here already";
                return oss.str();
            }
            building = command;
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
    if (type != "pas ")
        return "Can only do this for tiles of type pas";

    for (int i = 0; i < v_types.size(); ++i) {
        if (command == v_types[i]){
            ++workers[i];
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