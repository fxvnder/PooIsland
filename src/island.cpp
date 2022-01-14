#include "island.h"
#include "tile.h"
#include "utils.h"
#include "resources.h"

Island::Island(int l, int c) : resourcesVar(0,0,0,0,0,0,500), roundNum(0), playerNum(0){
    for (int i = 0; i < l; i++) {
        vecvec.add(poo::vector<Tile*>());
        for (int j = 0; j <= c; j++) {
            vecvec[i].add();
            vecvec[i][j] = randomTile(l,c);
        }
    }
}

Island::Island(const Island &old) :
    vecvec(old.vecvec),
    tile_types(old.tile_types),
    resourcesVar(old.resourcesVar)
{

}

std::string Island::showSimpleIsland() const {
    std::ostringstream oss;
    for (int i = 0; i < vecvec.size(); i++){
        for (int j = 0; j < vecvec[i].size(); j++){
            std::cout << vecvec[i][j]->showInfoTile() << " ";
        }
        std::cout << std::endl;
    }
    return oss.str();
}

std::string Island::showInfoIsland() const {
    std::ostringstream oss;
    //std::cout << vecvec.size() << vecvec[0].size() << std::endl;

    // vecvec.size(): lines
    // vecvec[i].size(): columns

    if (vecvec.empty()){ // if it's empty, give up
        oss << "ERROR: NO X AXIS ON ISLAND FOUND" << std::endl;
        return oss.str();
    } else
        if(vecvec[0].empty()) {
            oss << "ERROR: NO Y AXIS ON ISLAND FOUND" << std::endl;
            return oss.str();
        }

    //Exemplo interface:  ┐┌├ ┬ ─│
    //
    //      1    2    3    4    5
    //    ┌────┬────┬────┬────┬────┐
    //    │flr │pas │pan │flr │mnt │
    //   1│    │elec│    │    │mnF │
    //    │LO  │    │    │    │    │
    //    │2   │    │    │    │M   │
    //    ├────┼────┼────┼────┼────┤
    //    │pas │dsr │mnt │flr │mnt │
    //   2│    │bat │    │    │    │
    //    │    │O   │    │L   │    │
    //    │    │1   │    │1   │    │
    //    ├────┼────┼────┼────┼────┤
    //    │znX │mnt │pnt │dsr │mnt │
    //   3│    │mnC │    │    │    │
    //    │    │M   │    │    │M   │
    //    │    │1   │    │    │1   │
    //    ├────┼────┼────┼────┼────┤
    //    │mnt │pas │znX │pas │flr │
    //   4│    │    │    │    │    │
    //    │    │    │    │OOOO│    │
    //    │    │    │    │5   │    │
    //    └────┴────┴────┴────┴────┘

    // FIRST LINE
    for (int j = 1; j <= vecvec.size(); j++){
        if (j==1) { // first iteration
            for (int i = 1; i <= vecvec[0].size(); i++) { // ┌────┬────┬────┬────┬────┐
                if (i == 1) { // first iteration
                    oss << "┌";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                } else if (i == vecvec[0].size()) { // last iteration
                    oss << "┬";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                    oss << "┐" << std::endl;
                } else { // other iteration
                    oss << "┬";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                }
            }
        }

        // SECOND LINE
        if (j!=1) { // if not first iteration
            for (int i = 1; i <= vecvec[0].size(); i++) { // ├────┼────┼────┼────┼────┤
                std::string displayvar = vecvec[j - 1][i - 1]->type();
                if (i == 1) { // first iteration
                    oss << "├";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                } else if (i == vecvec[0].size()) { // last iteration
                    oss << "┼";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                    oss << "┤" << std::endl;
                } else { // other iteration
                    oss << "┼";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                }
            }
        }

        // THIRD LINE -- BIOME TYPE
        for (int i = 1; i <= vecvec[0].size(); i++) { // │flr │pas │pan │flr │mnt │
            std::string displayvar = vecvec[j - 1][i - 1]->type();
            if (i == 1) { // first iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "|" << displayvar;
            } else if (i == vecvec[0].size()) { // last iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "|" << displayvar << "|" << std::endl;
            } else { // other iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "│" << displayvar;
            }
        }

        // FOURTH LINE -- BUILDING TYPE
        for (int i = 1; i <= vecvec[0].size(); i++) { // │    │elec│    │    │mnF │
                std::string displayvar = vecvec[j - 1][i - 1]->buildingStr();
            if (i == 1) { // first iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "|" << displayvar;
            } else if (i == vecvec[0].size()) { // last iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "|" << displayvar << "|" << std::endl;
            } else { // other iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "│" << displayvar;
            }
        }

        // FIFTH LINE -- WORKERS
        for (int i = 1; i <= vecvec[0].size(); i++) { // │    │OOOO│    │    │MMMO│
            if (i == 1) { // first iteration
                oss << "|";
                for (int k = 0; k < TILEDISPSIZE; ++k) {
                    if (k >= vecvec[j - 1][i - 1]->workers().size())
                        oss << " ";
                    else
                        oss << vecvec[j - 1][i - 1]->workers()[k]->workerChar();
                }
            } else if (i == vecvec[0].size()) { // last iteration
                oss << "|";
                for (int k = 0; k < TILEDISPSIZE; ++k) {
                    if (k >= vecvec[j - 1][i - 1]->workers().size())
                        oss << " ";
                    else
                        oss << vecvec[j - 1][i - 1]->workers()[k]->workerChar();
                }
                oss << "|" << std::endl;
            } else { // other iteration
                oss << "|";
                for (int k = 0; k < TILEDISPSIZE; ++k) {
                    if (k >= vecvec[j - 1][i - 1]->workers().size())
                        oss << " ";
                    else
                        oss << vecvec[j - 1][i - 1]->workers()[k]->workerChar();
                }
            }
        }

        // SIXTH LINE
        if (j == vecvec.size()){ // last iteration
            for (int i = 1; i <= vecvec[0].size(); i++){ // └────┴────┴────┴────┴────┘

                if (i == 1) { // first iteration
                    oss << "└";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                } else if (i == vecvec[0].size()) { // last iteration
                    oss << "┴";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                    oss << "┘" << std::endl;
                } else { // other iteration
                    oss << "┴";
                    for (int k = 0; k < TILEDISPSIZE; ++k) { oss << "─"; }
                }
            }
        }
    }

    oss << "--- DAY NUMBER " << roundNum << " ---" << std::endl << std::endl;
    oss << "Cash: " << resourcesVar.money << "€" << std::endl;
    oss << "Iron: " << resourcesVar.iron << " - ";
    oss << "Steel: " << resourcesVar.steel_bar << " - ";
    oss << "Coal: " << resourcesVar.coal << " - ";
    oss << "Wood: " << resourcesVar.wood << " - ";
    oss << "Wood_plaques: " << resourcesVar.wood_plaques << " - ";
    oss << "Electricity: " << resourcesVar.electricity << std::endl;

    return oss.str();
}


void Island::changeDim(int l, int c){

    roundNum = 0;
    playerNum = 0;

    for (int i = 0 ; i < l ; ++i ) {
        vecvec.add(poo::vector<class Tile*>());
        for (int j = 0; j < c; ++j) {
            vecvec[i].add();
            vecvec[i][j] = randomTile(i+1, j+1);
        }
    }

    // Check if there's a tile type missing
    for (int i = 0; i < tile_types.size(); ++i){   //std::string type: vecvec[0][0].existingTypes()) {
        std::string typooo = tile_types[i]; //whyNeeded?
        if(!existsInIsland(typooo)){
            i = 0;
            vecvec[random(0,vecvec.size()-1)][random(0,vecvec[0].size()-1)]->type() = typooo;
        }
    }
}

Tile * Island::randomTile(int l, int c){
    Tile *p = nullptr;
    int rnd = random(0, tile_types.size()-1);
    switch (rnd) {
        case (0):
            p = new mountain(*this, l, c);
            break;
        case (1):
            p = new desert(*this, l, c);
            break;
        case (2):
            p = new pasture(*this, l, c);
            break;
        case (3):
            p = new forest(*this, l, c);
            break;
        case (4):
            p = new swamp(*this, l, c);
            break;
        case (5):
            p = new zoneX(*this, l, c);
            break;
        default:
            std::cout << "Error generating zone" << std::endl;
    }
    return p;
}

std::string Island::cont(const std::string& workertype) { // cont <type>
    std::ostringstream oss;
    int counter = 0;

    // COUNT PAS
    for (int i = 0; i < vecvec.size(); ++i) {
        for (int j = 0; j < vecvec[i].size(); ++j) {
            if (vecvec[i][j]->type() == "pas")
                ++counter;
        }
    }

    // RANDOMIZES PAS
    counter = random(1, counter);
    for (int i = 0; i < vecvec.size(); ++i) {
        for (int j = 0; j < vecvec[i].size(); ++j) {
            if (vecvec[i][j]->type() == "pas") {
                --counter;
                if (counter == 0) {
                    oss << vecvec[i][j]->cont(workertype);
                }
            }
        }
    }

    if (oss.str().empty()){
        oss << "SUCCESS: " << "Hiring " << workertype;
    } else oss << "ERROR: ";
    return oss.str();
}

std::string Island::move(std::string& workerID, int l, int c){
    std::ostringstream oss;
    std::stringstream workerIDstream;
    int workerIDint;

    // converts string to ostring
    workerIDstream << workerID;

    // converts ostring to int
    workerIDstream >> workerIDint;

    //std::cout << vecvec[1][3]->workers().size();
    for (int i = 0; i < vecvec.size(); ++i) {
        for (int j = 0; j < vecvec[0].size(); ++j) {
            for (int k = 0; k < vecvec[i][j]->workers().size(); ++k) {
                if (vecvec[i][j]->workers()[k]->giveIdentificador()[0] == workerIDint){
                    tile(l,c).workers().push_back(vecvec[i][j]->workers()[k]);
                    vecvec[i][j]->workers().erase(vecvec[i][j]->workers().begin()+k-1);
                }
            }
        }
    }

    oss << "SUCCESS:" << std::endl << "Moving Worker " << workerID << " to X=" << l << " and Y=" << c << std::endl;

    return oss.str();
}

bool Island::existsInIsland(const std::string& type) {
    for (int i = 1; i <= vecvec.size(); i++) {
        for (int j = 1; j <= vecvec[0].size(); j++){
            if (vecvec[i-1][j-1]->type() == type){
                return true;
            }
        }
    }
    return false;
}

int& Island::workerIDCounter(){
    return playerNum;
}
const int& Island::workerIDCounter() const{
    return playerNum;
}

Tile &Island::tile(int l, int c) {
    --l ; --c ;
    return *vecvec[l][c];
}

poo::vector<poo::vector<Tile*>> &Island::tiles() {
    return vecvec;
}

bool Island::isOutOfBounds(int l, int c) const {
    --l ; --c ;
    if (l < 0 || l > vecvec.size()-1 || c < 0 || c > vecvec[0].size()-1){
        return true;
    } // vecvec.size() size of columns (amount of lines)
    return false;
}

void Island::dawn(){
    std::cout << "It's dawn... ISLAND" << std::endl;
    for (int i = 1; i <= vecvec.size(); i++) {
        for (int j = 1; j <= vecvec[0].size(); j++){
            vecvec[i-1][j-1]->dawn();
        }
    }
}

void Island::dusk(){
    std::cout << "It's dusk... ISLAND" << std::endl;
    for (int i = 1; i <= vecvec.size(); i++) {
        for (int j = 1; j <= vecvec[0].size(); j++){
            vecvec[i-1][j-1]->dusk();
        }
    }
}

void Island::incRound(){
    roundNum++;
}

int Island::day() const {
    return roundNum;
}

int & Island::day() {
    return roundNum;
}

resourcesStr & Island::resources(){
    return resourcesVar;
}