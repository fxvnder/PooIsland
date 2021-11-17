#include <iostream>
#include "interface.h"
using namespace std;

void welcome(){
    std::cout << "Welcome to POOIsland" << std::endl;
    chooseDimensions();
}

void chooseDimensions() {
    int dim[2];
    bool success = false;
    // Lets player choose island dimensions
    do{
        std::cout << "Choose the island size: 1/2 ";
        std::cin >> dim[0];
        std::cout << "\nSize 2/2: ";
        std::cin >> dim[1];
        if (dim[0] >= 3 && dim[0] <= 8 && dim[1] >= 3 && dim[1] <= 16)
            success = true;
        else {
            std::cout << "\nInvalid data recieved, try again" << std::endl;
        }
    } while (!success);
    dim[0] = 6 ; dim[1] = 6;
    run(dim);
}

void plays(island world){
    std::string command = "",firstWord;
    std::string error_msg;
    do{
        if (error_msg != "")
            std::cout << error_msg << std::endl;
        error_msg = "";

        std::string error_msg = "";
        do{
            if (command != "")
                std::cout << "\nInvalid command, try again" << std::endl;
            command = "";
            getline(cin, command);
            firstWord = command.substr(0, command.find(" "));
            std::cout << "first word: " << firstWord << std::endl;
        } while (
                firstWord != "list" &&
                firstWord != "exec" &&
                firstWord != "cons"
                //...
                );

        error_msg = treatCommand(command,world);
    } while (error_msg != "");
};

std::string treatCommand(std::string command, island world){

    return "";
};