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

    std::cout << novo.display() << std::endl;
    return 0;
}