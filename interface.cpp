#include <iostream>
#include "interface.h"

void welcome(){
    std::cout << "Welcome to POOIsland" << std::endl;
    chooseDimensions();
}

void chooseDimensions() {
    int dim[2];
    bool success = false;
    do{
        std::cout << "Choose the island size: 1/2";
        std::cin >> dim[0];
        std::cout << "\nSize 2/2: ";
        std::cin >> dim[1];
        if (dim[0] >= 3 && dim[0] <= 8 && dim[1] >= 3 && dim[1] <= 16)
            success = true;
        else {
            std::cout << "\nInvalid data recieved, try again" << std::endl;
        }
    } while (!success);
}