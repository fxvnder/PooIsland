#ifndef POOISLAND_INTERFACE_H
#define POOISLAND_INTERFACE_H

#include "program.h"

class interface {
private:
    gameData game;
public:
    interface(gameData &game);

    // beautiful stuff
    static void welcome();
    static void showCredits();
    static std::string helpMe();

    // funcs
    void start();
    bool getNumber(int &userInp);
    void mainMenu();
    void newGame();
    void gameCycle();
    void plays(); //void plays(island& world, file& savegame);

    // treatCommand from program.h
    std::string treatCommand(std::string& commands);

    // vector that contains command strings
    std::vector<std::string> commandHistory;
};

bool loadGame(const std::string& filename);

#endif //POOISLAND_INTERFACE_H