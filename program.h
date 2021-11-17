#ifndef POOISLAND_PROGRAM_H
#define POOISLAND_PROGRAM_H
#include <vector>
#include <sstream>
#include <iostream>

class tile{
private:
    std::string type;
public:
    tile() : type("forest") {};
    std::string showInfoTile() const {
        std::ostringstream oss;
        oss << type << std::endl;
        return oss.str();
    };
    //std::string operator<< (const tile& type) const {return "nope"; };
};

class island{
private:
    int lines, columns;
    std::vector<std::vector<tile>> vecvec;
    std::vector<tile> vec;
public:
    island(int l,int c) : lines(l), columns(c) {
        for (int i = 0; i < l; ++i) {
            for (int j = 0; j < c; ++j) {
                tile moist;
                vec.push_back(moist);
            }
        }
    };
    std::string showInfoIsland() const {
        std::ostringstream oss;
        oss << "Showing Island Info" << std::endl;
        for (tile i : vec)
            oss << i.showInfoTile();
        oss << std::endl;
        return oss.str();
    };
};

int run();

#endif //POOISLAND_PROGRAM_H
