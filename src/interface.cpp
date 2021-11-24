#include <iostream>
#include "files.h"
#include "interface.h"
#include "objects.h"
#include "commands.h"

void welcome(){
    bool success = false;
    std::string userInp, filename;
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

    std::cout << welcome << "\nWelcome to PooIsland" << std::endl;
    do {
        std::cout << "\nWould you like to play a new game or load a saved one?\n1 - New Game\n2 - Load Game\n3 - Show Credits\n9 - Exit\n > ";
        std::cin >> userInp;
        if (userInp == "1"){
            success = true;
            newGame();
        } else if (userInp == "2") {
            std::cout << "\nWhat is the filename?\n >";
            std::cin >> filename;
            if(loadGame(filename)) {
                success = true;
            } else {
                std::cout << "\nThat does not seem very right... Try again.";
            }
        } else if (userInp == "3") {
            showCredits();
        } else if (userInp == "9") {
            exit(1);
        } else std::cout << "\nWell, that's odd... Try out again.";
    } while (!success);
}

void newGame() {
    int dim[2];
    bool success = false;

    // player chooses island dimensions
    do{
        std::cout << "Welcome to PooIsland! Let's start your game!\nChoose the island size: 1/2\n >";
        std::cin >> dim[0];
        std::cin.ignore(1,'\n');
        std::cout << "Size 2/2:\n >";
        std::cin >> dim[1];
        std::cin.ignore(1,'\n');
        if (dim[0] >= 3 && dim[0] <= 8 && dim[1] >= 3 && dim[1] <= 16){ // restrictions
            success = true;
        } else {
            std::cout << "\nInvalid data received, try again!\n" << std::endl;
        }
    } while (!success);
    createNewWorld(dim);
}

bool loadGame(const std::string& filename){
    if(checkFile(filename)){
        file savedFile = openFile(filename);
        createLoadedWorld(savedFile);
        return true;
    } else return false;
}

void plays(island& world, const file& savegame){
    std::string command;
    std::string msg;
    do {
        command.clear();
        do { // to prevent sending an empty string to treatCommand
            std::cout << "\nInsert a command\n> ";
            getline(std::cin, command);
        } while (command.empty());
        msg = treatCommand(command, world, savegame);
        std::cout << msg;
    } while (msg != "Continuing...\n");
}

void showCredits(){
    std::cout << "           %%%%%%%%%%%%                                                         \n"
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