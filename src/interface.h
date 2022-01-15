#ifndef POOISLAND_INTERFACE_H
#define POOISLAND_INTERFACE_H

#include <iostream>
#include <chrono>
#include "program.h"

class interface {
private:
    gameData game;
public:
    interface(gameData &game);

    // beautiful stuff
    static void welcome();
    void start();

    // funcs
    static bool getNumber(int &userInp);

    // real deal
    void mainMenu();
    void newGame();
    void gameCycle();
    void plays();
};

#endif //POOISLAND_INTERFACE_H