// #include <QCoreApplication>
// #include <QDebug>

#include <src/main2.h>



int main() {
    //QCoreApplication a(argc, argv);
    //qDebug() << "Hello World";
    //return QCoreApplication::exec();

    GameData game_on;
    Interface ui(game_on);
    ui.start();

    return 0;
}

