// #include <QCoreApplication>
// #include <QDebug>
#include "src/interface.h"

int main() {
    //QCoreApplication a(argc, argv);
    //qDebug() << "Hello World";
    //return QCoreApplication::exec();

    std::vector<std::string> nostress {"cons", "minaf", "3", "3"};
    island opo(4,4);
    opo.cons(nostress);
    std::cout << opo.showInfoIsland();
    //return 0;

    welcome();
    return 0;
}