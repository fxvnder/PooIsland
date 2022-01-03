#include "vector.h"
#include "vector.cpp" // to avoid linking issues, due to the template class
#include <iostream>
#include <iterator>
#include <ostream>

int main(){
    std::string a  = "oi", b = "ya";
    poo::mypair<std::string> mine(a,b);
    return 0;
}