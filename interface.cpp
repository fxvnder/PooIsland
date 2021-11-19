#include <iostream>
#include "interface.h"
#include "objects.h"
using std::cin;
using std::cout;
using std::string;

void welcome(){
    // my beautiful palm tree
    const char *welcome =
    "                   ****\n"
    "                 ********\n"
    "                **  ******\n"
    "                *   ******     ******\n"
    "            **      ******   *********\n"
    "           *  ****   ****  *****   ***\n"
    "                ***  ***  ***     ***\n"
    "                *************      **\n"
    " ____   ___    __**********____ _   *   ____  ____   ___   \n"
    "|    \\ /   \\  /   \\*******   _/| |     /    ||    \\ |   \\  \n"
    "|  o  )     ||     |H****H   \\_| |    |  o  ||  _  ||    \\ \n"
    "|   _/|  O  ||  O  |H   H\\__  || |___ |     ||  |  ||  D  |\n"
    "|  |  |     ||     |H-_-H/  \\ ||     ||  _  ||  |  ||     |\n"
    "|  |  |     ||     |H   H\\    ||     ||  |  ||  |  ||     |\n"
    "|__|   \\___/  \\___/ H-_-H\\____||_____||__|__||__|__||_____|";

    std::cout << welcome << "\nWelcome to POOIsland" << std::endl;
    chooseDimensions();
}

void chooseDimensions() {
    int dim[2];
    bool success = false;
    // player chooses island dimensions
    do{
        cout << "Choose the island size: 1/2 ";
        cin >> dim[0];
        cout << "\nSize 2/2: ";
        cin >> dim[1];
        if (dim[0] >= 3 && dim[0] <= 8 && dim[1] >= 3 && dim[1] <= 16) // restrictions
            success = true;
        else {
            cout << "\nInvalid data received, try again" << std::endl;
        }
    } while (!success);
    dim[0] = 6 ; dim[1] = 6;
    run(dim);
}

void plays(island world){
    string command, firstWord;
    string error_msg;
    do{
        if (!error_msg.empty()) {
            cout << error_msg << std::endl;
        }
        do{
            if (!command.empty())
                std::cout << "\nInvalid command, try again" << std::endl; // TODO: this is appearing even when the command is written right.
            command = "";
            getline(cin, command);
            firstWord = command.substr(0, command.find(' '));
            std::cout << "first word: " << firstWord << std::endl;
        } while (
                // LISTA DE COMANDOS
                firstWord != "exec" && // ex. comandos no ficheiro
                firstWord != "cons" && // constroi
                firstWord != "liga" && // liga edificio
                firstWord != "des" && // desliga edificio
                firstWord != "move" && // move trabalhador
                firstWord != "vende" && // vende recursos || vende edificios - CUIDADO COM ESTE
                firstWord != "cont" && // contrata trabalhador
                firstWord != "list" && // informacao jogo
                firstWord != "next" && // termina recolha
                firstWord != "save" && // grava em memoria
                firstWord != "load" && // carrega jogo em memoria
                firstWord != "apaga" && // apaga jogo em memoria
                firstWord != "config" && // le ficheiro de texto e extrai dados
                // COMANDOS DEBUG
                firstWord != "debcash" && // adiciona dinheiro
                firstWord != "debed" && // adiciona edificio
                firstWord != "debkill" && // remove trabalhador com X ID
                // sair
                firstWord != "exit" // sai
                );
        error_msg = treatCommand(command);
    } while (!error_msg.empty());
}

//region for later use

// creditos/ajuda
//"           %%%%%%%%%%%%                                                         \n"
//"       %%%%%%%%%%%%%%%%%%%%                                                 \n"
//"     %%%%%%%%%%%%%%%%%%%%%%%%                                                   \n"
//"   #%%%%%%%%%%%    %%%%%%%%%%%        %%%%  %%%%%%%%%%   %%%%%%%%%   %%%%%%%%%  \n"
//"  .%%%%%%%%%          %%%%%%%%%       %%%%  %%%%}       %%%____%%%% %%%%     \n"
//"  %%%%%%%%%            %%%%%%%%%      %%%%      {%%%%%  %%%         %%%%     \n"
//"  %%%%%%%%%            %%%%%%%%%      %%%%  #%%%%%%%%%   %%%%%%%%%   %%%%%%%%%. \n"
//"  %%%%%%%%%            %%%%%%%%%                    2021/2022                   \n"
//"  %%%%%%%%%            %%%%%%%%%                                               \n"
//"  %%%%%%%%%            %%%%%%%%%      Made by: Joao 'FXVNDER' Oliveira\n"
//"  %%%%%%%%%            %%%%%%%%%               Joao 'Yeshey' Almeida";

//endregion