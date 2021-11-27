//
// Created by yeshey on 27/11/21.
//

#ifndef POOISLAND_MAIN2_H
#define POOISLAND_MAIN2_H

#include "island.h"

class GameData {
private:
    island world;
public:
    GameData();
};

class Interface{
private:
public:
    Interface(GameData game_on);
    void start();
};


#endif //POOISLAND_MAIN2_H
