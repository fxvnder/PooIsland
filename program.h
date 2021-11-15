#ifndef POOISLAND_PROGRAM_H
#define POOISLAND_PROGRAM_H
#include <vector>
#include <sstream>
using std::vector;
using std::string;
using std::ostringstream;

class tiles{
private:
    string type;
public:
    tiles();
    string operator<< (const tiles& type) const {return "nope"; }; //?
};

class island{
private:
    int lines, columns;
    //vector<vector<tiles>> vec;
    vector<int> vec;
public:
    island(int l,int c);
    string showGuts() const;
};

int run();

#endif //POOISLAND_PROGRAM_H
