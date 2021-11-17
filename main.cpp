#include "program.h"
#include "interface.h"

#include <QCoreApplication>
#include <QDebug>
#include <iostream>
#include <vector>

int main(int argc, char *argv[]) {
    //QCoreApplication a(argc, argv);
    //qDebug() << "Hello World";
    //return QCoreApplication::exec();

    welcome();
    run();
}

/*
 * perguntar ao prof:
 *
 * -se deve meter os construtores no .h? e funções da classe
 * -melhor usar std::string ou pôr em cima "using std::string."

 Como se usa e para quê que se usa o new

  */