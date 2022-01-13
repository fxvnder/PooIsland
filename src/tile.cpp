#include "tile.h"
#include "program.h"
#include "utils.h"

Tile::Tile(Island & island, int l, int c) : building_class(nullptr), workersVec(), island_var(island) {
    // here it's saved as coords 1 1 for the tile in vector[0][0]
    coords[0] = l;
    coords[1] = c;

    // push back - cria uma copia do elemento e depois mete-o dentro do array
    // emplace back rouba os dados da cena que tamos a passar por referencia
    v_buildings.push_back("mnF");
    v_buildings.push_back("mnC");
    v_buildings.push_back("elec");
    v_buildings.push_back("bat");
    v_buildings.push_back("fun");
    v_buildings.push_back("sarr");
}
std::string Tile::showInfoTile() const {
    std::ostringstream oss;
    std::string tmp;

    std::string building_type;
    if (building_class == nullptr) {
        building_type = "";
    } else {
        building_type = building_class->type();
    }

    oss << "SUCCESS:" << std::endl;

    // first line
    oss << "┌";
    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
    oss << "┐" << std::endl;

    // second line - BIOME TYPE
    oss << "|" << typevar;
    for (int i = typevar.size(); i < TILEDISPSIZE; ++i)
        oss << " ";
    oss <<      "|" << std::endl;

    // third line - BUILDING TYPE
    oss << "|" << building_type;
    for (int i = building_type.size(); i < TILEDISPSIZE; ++i) {
        oss << " ";
    }

    oss <<      "|" << std::endl;

    // fourth line - WORKERS
    oss << "|";
    for (int k = 0; k < TILEDISPSIZE; ++k) {
        if (k >= workersVec.size())
            oss << " ";
        else
            oss << workersVec[k]->workerChar();
    }

    oss << "|" << std::endl;

    // the rest
    oss << "└";
    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
    oss << "┘" << std::endl;

    return oss.str();
}
std::string Tile::type() const{
    return typevar;
}
std::string& Tile::type(){
    return typevar;
}
std::string Tile::buildingStr(){
    //std::cout << building_class->type() << " | " << building_str << std::endl;
    if (building_class == nullptr) return "";
    return building_class->type();
}

Building* Tile::building(){
    //std::cout << building_class->type() << " | " << building_str << std::endl;
    //if (building_class == nullptr) return "";
    return building_class;
}

std::vector<Worker*>& Tile::workers(){
    return workersVec;
/*
    std::ostringstream oss;
    if (workers.empty()) return "";
    for (int i = 0; i < workers.size(); ++i) { // 4 is the graphical limit
        oss << workers[i];
    }
    return oss.str();
    */
}

std::string Tile::cons(const std::string& command) {
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
std::string Tile::build(std::string& command){
    std::ostringstream oss;
    for (int i = 0; i < v_buildings.size(); ++i) {
        if (command == strToLower(v_buildings[i])){
            if (building_class != nullptr) {
                oss << "ERROR: There's a " << command << " here already";
                return oss.str();
            }
            building_class = whichBuilding(v_buildings[i]);
            oss << "SUCCESS:" << std::endl << "building " << command << " in X=" << coords[0] << " Y=" << coords[1] << std::endl;
            return oss.str();
        }
    }
    oss << "ERROR: Wrong specified type, the existing types of buildings are: ";
    for (const std::string& str : v_buildings)
        oss << str << ' ';
    return oss.str();
}
Building* Tile::whichBuilding(std::string building){
    Building* p;
    
    if (building == "mnF"){ // IRonFarm
        p = new ironFarm(*this);
    } else if (building == "mnC"){ //coalMine
        p = new coalMine(*this);
    } else if (building == "elec"){ //electricityCentral
        p = new electricityCentral(*this);
    } else if (building == "bat"){ //battery
        p = new battery(*this);
    } else if (building == "fun"){ //foundry (fundição)
        p = new foundry(*this);
    } else if (building == "sarr"){ //Sarration
        p = new sarration(*this);
    } else {
        std::cout << "Error generating building" << std::endl;
    }
    return p;
}
std::string Tile::cont(const std::string& command){
    std::ostringstream oss;
    std::vector<std::string> v_types = {"miner", "len", "oper"};
    if (typevar != "pas")
        return "Can only do this for tiles of type pas";

    for (int i = 0; i < v_types.size(); ++i) {
        if (command == v_types[i]){

            switch (i) {
                case 0: // miner
                    workersVec.push_back(new miner(*this));
                    break;
                case 1: // len
                    workersVec.push_back(new lumberjack(*this));
                    break;
                case 2: // oper
                    workersVec.push_back(new operative(*this));
                    break;
                default:
                    std::cout << "ERROR: No worker type." << std::endl;
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
Island& Tile::island(){
    return island_var;
}

std::vector<Tile> Tile::adjacentZones(){
    // Passar como referencia exige menos do PC
    std::vector<Tile> vec;
    vec.push_back(island().tile(coords[0] - 1, coords[1])); // above
    vec.push_back(island().tile(coords[0], coords[1] + 1)); // right
    vec.push_back(island().tile(coords[0] + 1, coords[1])); // below
    vec.push_back(island().tile(coords[0], coords[1] - 1)); // left
    return vec;
}

// ===== Class mountain ===== //
mountain::mountain(Island &island,int l, int c) : Tile(island,l,c) {
    typevar = "pnt";
}

// ===== Class desert ===== //
desert::desert(Island &island,int l, int c) : Tile(island,l,c){
    typevar = "dsr";
}

// ===== Class pasture ===== //
pasture::pasture(Island &island,int l, int c) : Tile(island,l,c) {
    typevar = "pas";
}

// ===== Class forest ===== //
forest::forest(Island &island,int l, int c) : Tile(island,l,c), num_trees(0) {
    typevar = "flr";
}
int forest::trees() const {
    return num_trees;
}

// ===== Class swamp ===== //
swamp::swamp(Island &island,int l, int c) : Tile(island,l,c) {
    typevar = "pnt";
}

// ===== Class zonaX ===== //
zoneX::zoneX(Island &island,int l, int c) : Tile(island,l,c) {
    typevar = "znZ";
}