// #include <QCoreApplication>
// #include <QDebug>

#include "src/interface.h"

int main() {

    gameData game_on; // starts gameData
    interface ui(game_on); // starts the interface
    ui.start(); // begins program

    return 0;
}
