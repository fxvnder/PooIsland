#ifndef POOISLAND_INTERFACE_H
#define POOISLAND_INTERFACE_H

#include "program.h"



class interface{
private:
    gameData game;
public:
    interface(gameData &game);
    void start();
    bool getNumber(int &userInp);
    void welcome();
    //void showCredits();
    void mainMenu();
    void newGame();
    //std::string helpMe();
};


void welcome();
void newGame();
bool loadGame(const std::string& filename);
void plays(island& world, file& savegame);
void showCredits();
std::string helpMe();

#endif //POOISLAND_INTERFACE_H
