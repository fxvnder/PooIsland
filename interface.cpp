#include <iostream>
#include "files.h"
#include "interface.h"
#include "objects.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

void createNewWorld(int * dim){
    island world(dim[0], dim[1]);
    days(world);
}

void createLoadedWorld(int * dim){
    island world(dim[0], dim[1]);
    days(world);
}

void welcome(){
    bool success = false;
    string userInp, filename;
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

    cout << welcome << "\nWelcome to PooIsland" << endl;
    do {
        cout << "\nWould you like to play a new game or load a saved one?\n1 - New Game\n2 - Load Game\n3 - Show Credits\n9 - Exit\n > ";
        cin >> userInp;
        if (userInp == "1"){
            success = true;
            newGame();
        } else if (userInp == "2") {
            cout << "\nWhat is the filename?\n >";
            cin >> filename;
            if(loadGame(filename)) {
                success = true;
            } else {
                cout << "\nThat does not seem very right... Try again.";
            }
        } else if (userInp == "3") {
            showCredits();
        } else if (userInp == "9"){
            exit(1);
        } else cout << "\nWell, that's odd... Try out again.";
    } while (!success);
}

void newGame() {
    int dim[2];
    bool success = false;
    std::vector<string> commandsHistory;

    // player chooses island dimensions
    do{
        cout << "Welcome to PooIsland! Let's start your game!\nChoose the island size: 1/2\n >";
        cin >> dim[0];
        cin.ignore(1,'\n');
        cout << "Size 2/2:\n >";
        cin >> dim[1];
        cin.ignore(1,'\n');
        if (dim[0] >= 3 && dim[0] <= 8 && dim[1] >= 3 && dim[1] <= 16){ // restrictions
            success = true;
        } else {
            cout << "\nInvalid data received, try again!\n" << endl;
        }
    } while (!success);
    createNewWorld(dim);
}

bool loadGame(const string& filename){
    std::vector<string> commandsHistory;
    if(openFile(filename)){
        return true;
    } else return false;
}

void plays(const island& world){
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