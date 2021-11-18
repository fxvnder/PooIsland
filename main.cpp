#include "interface.h"

#include <QCoreApplication>
// #include <QDebug>
#include <iostream>

using std::cin;
using std::cout;
using std::string;
using std::endl;

int main(int argc, char *argv[]) {
    //QCoreApplication a(argc, argv);
    //qDebug() << "Hello World";
    //return QCoreApplication::exec();

    welcome();
    cout << "terminating successfuly" << endl;
    return 0;
}

/*
int main(){
    Jogo j; // Dados
    UserInt ui(j); // user interface (comandos)
    ui.run();

    //professor diz que é preciso separar a parte dos dados e da ui

    // meta 1
    // desmanchar a linha de texto em varios parametros
}*/

/*
 * perguntar ao prof:
 *
 * -se deve meter os construtores no .h? e funções da classe
 * -melhor usar std::string ou pôr em cima "using std::string."

 Como se usa e para quê que se usa o new

  */