#include <iostream>
#include "program.h"

/*
island::island(int l,int c) : lines(l), columns(c), vec(lines,42) {

};
*/

string island::showGuts() const {
    ostringstream oss;
    oss << "lets go " << 4;
    return oss.str();
};

int run(){
    island world(4,4);
    std::cout << world.showGuts() << std::endl;
    return 0;
}
