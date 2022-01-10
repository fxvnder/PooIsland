#ifndef POOISLAND_INTERFACE_H
#define POOISLAND_INTERFACE_H

#include <iostream>
#include "program.h"

class interface {
private:
    gameData game;
public:
    interface(gameData &game);

    // beautiful stuff
    static void welcome();

    // funcs
    void start();
    bool getNumber(int &userInp);
    void mainMenu();
    void newGame();
    void gameCycle();
    void plays(); //void plays(island& world, file& savegame);
};

#endif //POOISLAND_INTERFACE_H