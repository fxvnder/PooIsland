#ifndef POOISLAND_PROGRAM_H
#define POOISLAND_PROGRAM_H
#include <vector>
using std::vector;

class island{
private:
    int lines, columns;
    // vector<vector<int>> vect;
    vector<int> vec;

public:
    island(int l,int c) : lines(l), columns(c) {
        
    };
};

int run();

#endif //POOISLAND_PROGRAM_H
