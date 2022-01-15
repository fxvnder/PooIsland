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

    oss << "Number of workers present in this tile: " << workersVec.size() << std::endl;
    for (int k = 0; k < workersVec.size(); ++k){
        oss << workersVec[k]->workerChar() << ":";
        oss << workersVec[k]->giveIdentificador()[0] << "." << workersVec[k]->giveIdentificador()[1] << " ";
    }
    oss << std::endl << "Tile resources: " << std::endl;
    oss << "Iron: " << resources_var.iron << " - ";
    oss << "Steel: " << resources_var.steel_bar << " - ";
    oss << "Coal: " << resources_var.coal << " - ";
    oss << "Wood: " << resources_var.wood << " - ";
    oss << "Wood_plaques: " << resources_var.wood_plaques << " - ";
    oss << "Electricity: " << resources_var.electricity << std::endl;

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
}

std::string Tile::build(std::string& command){
    std::ostringstream oss;
    for (int i = 0; i < v_buildings.size(); ++i) {
        if (command == strToLower(v_buildings[i])){
            if (building_class != nullptr) {
                oss << "ERROR: There's a " << command << " here already";
                return oss.str();
            }
            building_class = whichBuilding(v_buildings[i], true);
            oss << "SUCCESS:" << std::endl << "Building " << command << " in X=" << coords[0] << " and Y=" << coords[1] << std::endl;
            return oss.str();
        }
    }
    oss << "ERROR: Wrong specified type, the existing types of buildings are: ";
    for (const std::string& str : v_buildings)
        oss << str << ' ';
    return oss.str();
}

std::string Tile::buildNoCost(std::string& command){
    std::ostringstream oss;
    for (int i = 0; i < v_buildings.size(); ++i) {
        if (command == strToLower(v_buildings[i])){
            if (building_class != nullptr) {
                oss << "ERROR: There's a " << command << " here already";
                return oss.str();
            }
            building_class = whichBuilding(v_buildings[i], false);
            oss << "SUCCESS:" << std::endl << "Building " << command << " in X=" << coords[0] << " and Y=" << coords[1] << std::endl;
            return oss.str();
        }
    }
    oss << "ERROR: Wrong specified type, the existing types of buildings are: ";
    for (const std::string& str : v_buildings)
        oss << str << ' ';
    return oss.str();
}

Building* Tile::whichBuilding(std::string building, bool costmoney){
    Building *p = nullptr;
    bool success = false;

    // IronFarm
    if (building == "mnF"){
        if (!costmoney){
            p = new ironFarm(*this);
            success = true;
        }

        if(!success) { std::cout << "ERROR: You don't have enough resources!"; }


    // CoalMine
    } else if (building == "mnC"){
//        if(costmoney) {
//            for (int i = 0; i < 10; ++i) {
//                if(island().resources().wood_plaques > 0) {
//                    island().resources().wood_plaques--;
//                }
//            }
//        }
        if (!costmoney) {
            p = new coalMine(*this);
            success = true;
        }

        if(!success) { std::cout << "ERROR: You don't have enough resources!"; }


    // ElectricityCentral
    } else if (building == "elec"){
        if(costmoney && island().resources().money >= 15) {
            island().resources().money -= 15;
            p = new electricityCentral(*this);
            success = true;
        }
        if(!costmoney){
            p = new electricityCentral(*this);
            success = true;
        }

        if(!success) { std::cout << "ERROR: You don't have enough resources!"; }


    // Battery
    } else if (building == "bat"){
        if (costmoney && island().resources().money >= 10 && island().resources().wood_plaques >=10){
            island().resources().money -= 10;
            island().resources().wood_plaques -= 10;
            p = new battery(*this);
            success = true;
        }
        if (!costmoney){
            p = new battery(*this);
            success = true;
        }

        if(!success) { std::cout << "ERROR: You don't have enough resources!"; }


    // Foundry (fundição)
    } else if (building == "fun"){
        if (costmoney && island().resources().money >= 10){
            island().resources().money -= 10;
            p = new foundry(*this);
            success = true;
        }

        if (!costmoney){
            p = new foundry(*this);
            success = true;
        }

        if(!success) { std::cout << "ERROR: You don't have enough resources!"; }


    // Sarration
    } else if (building == "sarr"){
        if (!costmoney){
            p = new sarration(*this);
            success = true;
        }

        if(!success) { std::cout << "ERROR: You don't have enough resources!"; }


    // Error
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
Island& Tile::island() const{
    return island_var;
}

Tile::~Tile(){
    for (Worker* w : workersVec) {
        delete w;
    }
}
resourcesStr& Tile::resources() {
    return resources_var;
}
bool Tile::atLeastOneWorkerOfType(std::string const & str) const{
    for (Worker* w : workersVec) { // oper, miner, len
        if (w->type() == str)
            return true;
    }
    return false;
}
Tile* Tile::ptrToAdjacentTileOfType(const std::string& type) const{
    /*
    std::vector<Tile> vec;
    vec.push_back(island().tile(coords[0] - 1, coords[1])); // above
    vec.push_back(island().tile(coords[0], coords[1] + 1)); // right
    vec.push_back(island().tile(coords[0] + 1, coords[1])); // below
    vec.push_back(island().tile(coords[0], coords[1] - 1)); // left
*/
    // above
    if (!island().isOutOfBounds(coords[0] - 1, coords[1]))
        if (island().tile(coords[0] - 1, coords[1]).type() == type)
            return &island().tile(coords[0] - 1, coords[1]);

    // right
    if (!island().isOutOfBounds(coords[0], coords[1] + 1))
        if (island().tile(coords[0], coords[1] + 1).type() == type)
            return &island().tile(coords[0], coords[1] + 1);

    // below
    if (!island().isOutOfBounds(coords[0] + 1, coords[1]))
        if (island().tile(coords[0] + 1, coords[1]).type() == type)
            return &island().tile(coords[0] + 1, coords[1]);

    // left
    if (!island().isOutOfBounds(coords[0], coords[1] - 1))
        if (island().tile(coords[0], coords[1] - 1).type() == type)
            return &island().tile(coords[0], coords[1] - 1);

    return nullptr;
}
bool Tile::atLeastOneAdjacentTileOfType(const std::string& type) const {
    if (ptrToAdjacentTileOfType(type) == nullptr) return false;
    return true;
}
Tile* Tile::ptrToAdjacentTileWithBuildingOfType(const std::string& type) const{
    // above
    if (!island().isOutOfBounds(coords[0] - 1, coords[1]))
        if (island().tile(coords[0] - 1, coords[1]).building() != nullptr)
            if (island().tile(coords[0] - 1, coords[1]).building()->type() == type)
                return &island().tile(coords[0] - 1, coords[1]);

    // right
    if (!island().isOutOfBounds(coords[0], coords[1] + 1))
        if (island().tile(coords[0], coords[1] + 1).building() != nullptr)
            if (island().tile(coords[0], coords[1] + 1).building()->type() == type)
                return &island().tile(coords[0], coords[1] + 1);

    // below
    if (!island().isOutOfBounds(coords[0] + 1, coords[1]))
        if (island().tile(coords[0] + 1, coords[1]).building() != nullptr)
            if (island().tile(coords[0] + 1, coords[1]).building()->type() == type)
                return &island().tile(coords[0] + 1, coords[1]);

    // left
    if (!island().isOutOfBounds(coords[0], coords[1] - 1))
        if (island().tile(coords[0], coords[1] - 1).building() != nullptr)
            if (island().tile(coords[0], coords[1] - 1).type() == type)
                return &island().tile(coords[0], coords[1] - 1);

    return nullptr;
}
void Tile::dawn() { }
void Tile::dusk() {
    if (building_class != nullptr)
        building_class->dusk();
}


// ===== Class mountain ===== //
mountain::mountain(Island &island,int l, int c) : Tile(island,l,c) {
    typevar = "mnt";
}
void mountain::dawn() {
}

// ===== Class desert ===== //
desert::desert(Island &island,int l, int c) : Tile(island,l,c){
    typevar = "dsr";
}
void desert::dawn() {
}

// ===== Class pasture ===== //
pasture::pasture(Island &island,int l, int c) : Tile(island,l,c) {
    typevar = "pas";
}
void pasture::dawn() {

}

// ===== Class forest ===== //
forest::forest(Island &island,int l, int c) : Tile(island,l,c), num_trees(random(20,40)) {
    typevar = "flr";

}
void forest::dawn() {
    if (num_trees > 0)
        for (Worker* pw : workersVec) {
            if (pw->workerChar()=='L') {
                resources_var.wood++;
            }
        }
    if (building_class != nullptr)
        if (num_trees > 0) --num_trees;
    else
        if (num_trees < 100)
            if (island().day() % 2 == 0)
                ++num_trees;
}
int forest::trees() const {
    return num_trees;
}

// ===== Class swamp ===== //
swamp::swamp(Island &island,int l, int c) : Tile(island,l,c) {
    typevar = "pnt";
}
void swamp::dawn() {
    if (building_class != nullptr)
        ++daysSinceBuilding;
    if (daysSinceBuilding == 10){
        for (Worker* w : workersVec) {
            delete w;
        }
        workersVec.clear();
    }
}

// ===== Class zonaX ===== //
zoneX::zoneX(Island &island,int l, int c) : Tile(island,l,c) {
    typevar = "znZ";
}
void zoneX::dawn() {

}