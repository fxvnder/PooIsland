#include "vector.h"
//#include "vector.cpp" // to avoid linking issues, due to the template class
#include <iostream>
#include <iterator>
#include <ostream>
#include <sstream>
#include <string>

int main(){
    std::string a  = "oi", b = "ya";
    poo::vector<std::string> meme{};

    meme.add(a);
    meme.add(b);
    meme.add(b);
    meme.add(b);
    meme.add(b);
    meme.add(b);
    meme[5] = "omg";

    std::cout << meme.display() << std::endl;

    poo::vector<std::string> novo = meme;

    meme.add(a);
    novo = meme;

    std::cout << novo.display() << "size: " << novo.size() << std::endl;

    std::cout << "==========================" << std::endl;

    poo::vector<poo::vector<int>> vecvec{};

    for (int i = 0, k=0; i < 10; ++i) {
        vecvec.add();
        for (int j = 0; j < 10; ++j) {
            vecvec[i].add(++k);
        }
    }

    vecvec[5][5] = 100;

    for (int i = 0, k=0; i < vecvec.size(); ++i) {
        //std::cout << vecvec[i].display() << std::endl;
        for (int j = 0; j < vecvec[i].size(); ++j) {
            std::cout << vecvec[i][j] << "\t";
        }
        std::cout << std::endl;
    }

    for (int i = 0, k=0; i < vecvec.size(); ++i) {
        std::cout << vecvec[i].display() << std::endl;
    }

    std::cout << vecvec;

    return 0;
}