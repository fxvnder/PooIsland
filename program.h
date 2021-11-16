#ifndef POOISLAND_PROGRAM_H
#define POOISLAND_PROGRAM_H
#include <vector>
#include <sstream>

class tiles{
private:
    std::string type;
public:
    tiles() : type("forest") {};
    std::string operator<< (const tiles& type) const {return "nope"; };
};

class island{
private:
    int lines, columns;
    //vector<vector<tiles>> vec;
    std::vector<tiles> vec;
public:
    island(int l,int c) : lines(l), columns(c) {
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < c; ++j) {
                vec.push_back()
            }
        }
    };
    std::string showGuts() const;
};

int run();

#endif //POOISLAND_PROGRAM_H
