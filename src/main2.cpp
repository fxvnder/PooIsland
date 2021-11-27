//
// Created by yeshey on 27/11/21.
//

#include "main2.h"
#include "interface.h"

GameData::GameData() : world(0,0){
}

Interface::Interface(GameData game_on) {
};
void Interface::start() {
    welcome();
    return;
};