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

Island::Island(const Island &old) : tile_types(old.tile_types), resourcesVar(old.resourcesVar), roundNum(old.roundNum), playerNum(old.playerNum) {
    //vecvec(old.vecvec),
    for (int i = 0 ; i < old.vecvec.size() ; ++i ) {
        vecvec.add(poo::vector<class Tile*>());
        for (int j = 0; j < old.vecvec[0].size(); ++j) {
            vecvec[i].add();
            vecvec[i][j] = theRightTileDup(*old.vecvec[i][j], i , j);
            vecvec[i][j]->dup(old.vecvec[i][j], *this) ;
        }
    }
}

Tile* Island::theRightTileDup(Tile boy, int l, int c){
    Tile *p = nullptr;
    bool found = false;
    int k;
    for (k = 0 ; k < tile_types.size() ; ++k) {
        if (tile_types[k] == boy.type()) {
            found = true;
            break;
        }
    }
    if (!found) return p;

    switch (k) {
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

std::vector<int> Island::workerNums(){
    std::vector<int> workerNumsVec;
    int opers = 0, miners = 0, lumbs = 0;

    for (int i = 0; i < vecvec.size(); ++i) {
        for (int j = 0; j < vecvec[0].size(); ++j) {
            for (int k = 0; k < vecvec[i][j]->workers().size(); ++k) {
                if(vecvec[i][j]->workers()[k]->type() == "oper"){
                    opers++;
                } else if (vecvec[i][j]->workers()[k]->type() == "miner") {
                    miners++;
                } else if (vecvec[i][j]->workers()[k]->type() == "len") {
                    lumbs++;
                }
            }
        }
    }

    workerNumsVec.push_back(opers);
    workerNumsVec.push_back(miners);
    workerNumsVec.push_back(lumbs);

    return workerNumsVec;
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

std::string Island::showInfoIsland(double time) {
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

    oss << "SUCCESS! Showing island information:" << std::endl;


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
                    oss << "┐";
                    if (j==1) oss << " Description:";
                    oss << std::endl;
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
                oss << "│" << displayvar;
            } else if (i == vecvec[0].size()) { // last iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "│" << displayvar << "│";
                if (j==1) oss << " < zone type";
                oss << std::endl;
            } else { // other iteration
                while (displayvar.size() < TILEDISPSIZE) { displayvar += ' '; }
                oss << "│" << displayvar;
            }
        }

        // FOURTH LINE -- BUILDING TYPE
        for (int i = 1; i <= vecvec[0].size(); i++) { // │    │elec│    │    │mnF │
            if (i==1) { }
            oss << "│" << vecvec[j - 1][i - 1]->buildingStr();
            for (int k = vecvec[j - 1][i - 1]->buildingStr().size(); k < TILEDISPSIZE; ++k ){
                oss << " ";
            }
            if (i==vecvec[0].size()) {
                oss << "│";
                if (j==1) oss << " < building type";
                oss << std::endl;
            }
        }

        // FIFTH LINE -- WORKERS
        for (int i = 1; i <= vecvec[0].size(); i++) { // │    │OOOO│    │    │MMMO│
            std::ostringstream tmposs;
            for (Worker* pw : vecvec[j - 1][i - 1]->workers()) {
                tmposs << pw->workerChar()
                       << pw->giveIdentifier()[0]
                       << "."
                       << pw->giveIdentifier()[1]
                       << " ";
            }
            oss << "│";
            if (tmposs.str().size() > TILEDISPSIZE){
                for (int k = 0; k < TILEDISPSIZE; ++k) {
                    if (k >= vecvec[j - 1][i - 1]->workers().size())
                        oss << " ";
                    else
                        oss << vecvec[j - 1][i - 1]->workers()[k]->workerChar();
                }
            } else {
                for (int o = tmposs.str().size(); o < TILEDISPSIZE; o++ ) {
                    tmposs << " ";
                }
                oss << tmposs.str();
            }
            if (i == vecvec[0].size()){
                oss << "│";
                if (j==1) oss << " < workers";
                oss << std::endl;
            }
        }

        for (int i = 1; i <= vecvec[0].size(); i++) { // │    │WCC │    │SEEE│CCC │
            if (i==1) { }
            std::string tmposs = "";
            // iron I  steel S  coal C  wood W  wood_plaques w  electricity E  money
            oss << "│";
            for (int k = 0; k < vecvec[j-1][i-1]->resources().iron && tmposs.size() < TILEDISPSIZE; ++k ){ tmposs += "I"; }
            for (int k = 0; k < vecvec[j-1][i-1]->resources().steel_bar && tmposs.size() < TILEDISPSIZE; ++k ){ tmposs += "S"; }
            for (int k = 0; k < vecvec[j-1][i-1]->resources().coal && tmposs.size() < TILEDISPSIZE; ++k ){ tmposs += "C"; }
            for (int k = 0; k < vecvec[j-1][i-1]->resources().wood && tmposs.size() < TILEDISPSIZE; ++k ){ tmposs += "W"; }
            for (int k = 0; k < vecvec[j-1][i-1]->resources().wood_plaques && tmposs.size() < TILEDISPSIZE; ++k ){ tmposs += "w"; }
            for (int k = 0; k < vecvec[j-1][i-1]->resources().electricity && tmposs.size() < TILEDISPSIZE; ++k ){ tmposs += "E"; }
            while ( tmposs.size() < TILEDISPSIZE){ tmposs += " "; }

            oss << tmposs;
            if (i==vecvec[0].size()) {
                oss << "│";
                if (j==1) oss << " < zone resources";
                oss << std::endl;
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

    updateGlobalResources();

    oss << "--- DAY NUMBER " << roundNum << " ---" << std::endl;
    oss << "Time of day: " << timeOfDay(round(86400*time/DAYTIME)) << std::endl;

    oss << "Island Resources:" << std::endl;
    oss << "Cash: " << resourcesVar.money << "€" << std::endl;
    oss << "Iron: " << resourcesVar.iron << " - ";
    oss << "Steel: " << resourcesVar.steel_bar << " - ";
    oss << "Coal: " << resourcesVar.coal << " - ";
    oss << "Wood: " << resourcesVar.wood << " - ";
    oss << "Wood_plaques: " << resourcesVar.wood_plaques << " - ";
    oss << "Electricity: " << resourcesVar.electricity << std::endl << std::endl;

    oss << "Island Workers:" << std::endl;
    oss << "Operators: " << workerNums()[0] << " - ";
    oss << "Miners: " << workerNums()[1] << " - ";
    oss << "Lumberjacks: " << workerNums()[2];


    return oss.str();
}

void Island::updateGlobalResources(){
    resourcesVar.iron = 0;
    resourcesVar.steel_bar = 0;
    resourcesVar.coal = 0;
    resourcesVar.wood = 0;
    resourcesVar.wood_plaques = 0;
    resourcesVar.electricity = 0;
    for (int y = 1; y <= vecvec.size(); ++y) { // lines
        for (int x = 1; x <= vecvec[0].size(); ++x) { // columns
            resourcesVar.iron += tile(y,x).resources().iron;
            resourcesVar.steel_bar += tile(y,x).resources().steel_bar;
            resourcesVar.coal += tile(y,x).resources().coal;
            resourcesVar.wood += tile(y,x).resources().wood;
            resourcesVar.wood_plaques += tile(y,x).resources().wood_plaques;
            resourcesVar.electricity += tile(y,x).resources().electricity;
        }
    }
}
std::string Island::timeOfDay(int n){
    std::ostringstream oss;
    // DAYTIME
    int hourTime = DAYTIME / 24;
    int secondTime = hourTime / 60;

    n = n % (24 * 3600);
    int hour = n / 3600;

    n %= 3600;
    int minutes = n / 60 ;

    n %= 60;
    int seconds = n;

    oss << hour
        << " " << "hours " << minutes << " "
        << "minutes " << seconds << " "
        << "seconds "  << std::endl;
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
                if (vecvec[i][j]->workers()[k]->giveIdentifier()[0] == workerIDint){
                    tile(l,c).workers().push_back(vecvec[i][j]->workers()[k]);
                    tile(l,c).workers()[k] = vecvec[i][j]->workers()[k];
                    vecvec[i][j]->workers().erase(vecvec[i][j]->workers().begin()+k);
                }
            }
        }
    }

    oss << "SUCCESS:" << std::endl << "Moving Worker " << workerID << " to X=" << l << " and Y=" << c << std::endl;

    return oss.str();
}

std::string Island::debkill(int workerID, bool quit){
    std::ostringstream oss;
    bool found = false;
    int l, c;
    std::string typeW;

    for (int i = 0; i < vecvec.size(); ++i) {
        for (int j = 0; j < vecvec[0].size(); ++j) {
            for (int k = 0; k < vecvec[i][j]->workers().size(); ++k) {
                if (vecvec[i][j]->workers()[k]->giveIdentifier()[0] == workerID){
                    typeW = vecvec[i][j]->workers()[k]->type();
                    vecvec[i][j]->workers().erase(vecvec[i][j]->workers().begin()+k);
                    found = true;
                    l = i; c = j;
                }
            }
        }
    }

    if (quit) {
        std::cout << "\nThe " << typeW << " with the ID " << workerID << " from X=" << l+1 << " and Y=" << c+1 << " has quit his job." << std::endl;
        oss << "SUCCESS";
        return oss.str();
    }

    if (found) {
        oss << "SUCCESS: " << std::endl << "Removed worker " << workerID << " from X=" << l+1 << " Y=" << c+1 << std::endl;
    } else oss << "ERROR: Worker was not found!" << std::endl;

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
    for (int i = 1; i <= vecvec.size(); i++) {
        for (int j = 1; j <= vecvec[0].size(); j++){
            vecvec[i-1][j-1]->dawn();
        }
    }
}

void Island::dusk(){
    for (int i = 1; i <= vecvec.size(); i++) {
        for (int j = 1; j <= vecvec[0].size(); j++){

            // checks workers conditions
            for (int k = 0; k < tile(i,j).workers().size(); ++k) {

                // for oper
                if(tile(i,j).workers()[k]->workerChar() == 'O'){
                    bool isHeGonnaQuit = false;
                    if(day() >= 10){
                        if(random(0,100) <= 5){
                            isHeGonnaQuit = true;
                        }
                    }
                    if(isHeGonnaQuit){
                        debkill(tile(i,j).workers()[k]->giveIdentifier()[0], true);
                    }

                // for lenhador
                } else if (tile(i,j).workers()[k]->workerChar() == 'L'){
                    bool isHeGonnaQuit = false;
                    if(day() % 5 == 0) {
                        tile(i,j).workers()[k]->togglerestday(true);
                    } else tile(i,j).workers()[k]->togglerestday(false);

                    if(random(0,100) <= 1){
                        isHeGonnaQuit = true;
                    }

                    if(isHeGonnaQuit){
                        debkill(tile(i,j).workers()[k]->giveIdentifier()[0], true);
                    }

                // for miner
                } else if (tile(i,j).workers()[k]->workerChar() == 'M'){
                    bool isHeGonnaQuit = false;
                    if(day() >= 2){
                        if(random(0,100) <= 10){
                            isHeGonnaQuit = true;
                        }
                    }
                    if(isHeGonnaQuit){
                        debkill(tile(i,j).workers()[k]->giveIdentifier()[0], true);
                    }
                }

            // does dusk on X, Y
            vecvec[i-1][j-1]->dusk();
            }
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