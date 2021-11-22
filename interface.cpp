#include <iostream>
#include "interface.h"
#include "objects.h"
using std::cin;
using std::cout;
using std::string;
using std::endl;

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

    cout << welcome << "\nWelcome to POOIsland" << endl;
    chooseDimensions();
}

void chooseDimensions() {
    int dim[2];
    bool success = false;
    // player chooses island dimensions
    do{
        cout << "Choose the island size: 1/2 ";
        cin >> dim[0];
        cin.ignore(1,'\n');
        cout << "Size 2/2: ";
        cin >> dim[1];
        cin.ignore(1,'\n');
        if (dim[0] >= 3 && dim[0] <= 8 && dim[1] >= 3 && dim[1] <= 16) // restrictions
            success = true;
        else {
            cout << "\nInvalid data received, try again" << endl;
        }
    } while (!success);
    run(dim);
}

void plays(island world){
    string command, firstWord;
    string msg;
    do {
        command.clear();
        do { // to prevent sending an empty string to treatCommand
            cout << "\nInsert a command\n> ";
            getline(cin, command);
        } while (command.empty());
        msg = treatCommand(command, world);
        firstWord = msg.substr(0, msg.find(' '));
        cout << msg;
    } while (firstWord != "Continuing...\n");
}

void showCredits(){
    cout << "           %%%%%%%%%%%%                                                         \n"
            "       %%%%%%%%%%%%%%%%%%%%                                                     \n"
            "     %%%%%%%%%%%%%%%%%%%%%%%%                                                   \n"
            "   #%%%%%%%%%%%    %%%%%%%%%%%        %%%%  %%%%%%%%%%   %%%%%%%%%   %%%%%%%%%  \n"
            "  .%%%%%%%%%          %%%%%%%%%       %%%%  %%%%}       %%%____%%%% %%%%        \n"
            "  %%%%%%%%%            %%%%%%%%%      %%%%      {%%%%%  %%%         %%%%        \n"
            "  %%%%%%%%%            %%%%%%%%%      %%%%  #%%%%%%%%%   %%%%%%%%%   %%%%%%%%%. \n"
            "  %%%%%%%%%            %%%%%%%%%                    2021/2022                   \n"
            "  %%%%%%%%%            %%%%%%%%%                                                \n"
            "  %%%%%%%%%            %%%%%%%%%      Made by: Joao 'FXVNDER' Oliveira\n"
            "  %%%%%%%%%            %%%%%%%%%               Joao 'Yeshey' Almeida\n";
}