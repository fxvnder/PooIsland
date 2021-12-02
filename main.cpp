// #include <QCoreApplication>
// #include <QDebug>

#include <src/interface.h>

int main() {
    //QCoreApplication a(argc, argv);
    //qDebug() << "Hello World";
    //return QCoreApplication::exec();

    gameData game_on;
    interface ui(game_on);
    ui.start();

    return 0;
}

