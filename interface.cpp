#include <iostream>

void bemVindo(){
    std::cout << "Bem vindo ao POOIsland" << std::endl;
    quantosQuadrados();
}

void quantosQuadrados() {
    int dim[2];
    bool success = false;
    do{
        std::cout << "Qual o tamanho que quer que o seu mundo tenha? Tamanho 1/2: ";
        std::cin >> dim[0];
        std::cout << "\nTamanho 2/2: ";
        std::cin >> dim[1];
        if (dim[0] >= 3 && dim[0] <= 8 && dim[1] >= 3 && dim[1] <= 16)
            success = true;
        else {
            std::cout << "\nDados invalidos! Introduza novamente!" << std::endl;
        }
    } while (!success);
}