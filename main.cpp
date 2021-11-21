#include "interface.h"

#include <QCoreApplication>
// #include <QDebug>
#include <iostream>

int main() {
    //QCoreApplication a(argc, argv);
    //qDebug() << "Hello World";
    //return QCoreApplication::exec();
    for (int i=0;i<100;++i){
        int finalNum = rand()%(10+1);
        std::cout << finalNum << endl;
    }

    welcome();
    return 0;
}