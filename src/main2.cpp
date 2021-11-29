#include "main2.h"
#include "interface.h"

GameData::GameData() : world(0,0){
}
island GameData::getIsland(){
    return world;
};

Interface::Interface(GameData &game_on) : world(game_on.getIsland()){

};
void Interface::start() {
    welcome();
    return;
};