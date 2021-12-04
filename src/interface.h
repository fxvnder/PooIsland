#ifndef POOISLAND_INTERFACE_H
#define POOISLAND_INTERFACE_H

#include "program.h"

class interface {
private:
    gameData game;
public:
    interface(gameData &game);
    void start();
    bool getNumber(int &userInp);
    void welcome();
    void mainMenu();
    void newGame();
    void gameCycle();
    void plays(); //void plays(island& world, file& savegame);
    void showCredits();
    std::string helpMe();
    std::string treatCommand(std::string& commands);
};

bool loadGame(const std::string& filename);

#endif //POOISLAND_INTERFACE_H