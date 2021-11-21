#include "objects.h"
#include <iostream>
#include <sstream>
#include <vector>

using std::ostringstream;
using std::vector;
using std::cout;
using std::endl;

//class tiles
tile::tile() {
    vector<string> v_types = {"pnt ","dsr ", "pas ", "flr ", "pnt ", "znZ ", "mnF ", "mnC ", "elec", "bat ", "fun "};
    type = v_types[ rand()%(v_types.size()) ];
    // access the island here
};
string tile::showInfoTile() const {
    ostringstream oss;
    oss << type;
    return oss.str();
};


//class island
island::island(int l,int c) : lines(l), columns(c) {
    for (int i = 0; i < l; ++i) {
        vecvec.push_back(vector<tile>());
        for (int j = 0; j < c; ++j) {
            tile newTile;
            vecvec[i].push_back(newTile);
        }
    }
};
string island::showInfoIsland() const {
    ostringstream oss;
    oss << "Showing Island Info" << endl;

    for (const vector<tile> &vec : vecvec){
        for (const tile &x : vec)
            oss << x.showInfoTile() << " ";
        oss << endl;
    }

    int i=0,j=0;
    //-----Print the island-----
    printf("  ");
    for(i=0;i<vecvec.size();i++) // size of columns
        printf(" C%d ",i);
    putchar('\n');

    printf("   ");
    for(i=0;i<vecvec.size();i++)
        if(i!=vecvec.size()-1)
            oss << "----";
        else
            oss << "---";
    oss << '\n';

    for(i=0;i<vecvec[0].size();i++){
        oss << 'L' << vecvec[i][j].showInfoTile() << "|" << endl;
        for(j=0;j<vecvec.size()-1;j++){
            oss << vecvec[i][j].showInfoTile() << endl;
        }
        oss << ' ' << vecvec[i][j].showInfoTile() << " |" << endl;

        if(i!=ptable->nlin-1){
            printf("  |");
            for(j=0;j<ptable->ncol-1;j++)
                printf("---:");
            printf("---|\n");
        }
    }
    printf("   ");
    for(i=0;i<ptable->ncol;i++)
        if(i!=ptable->ncol-1)
            printf("----");
        else
            printf("---");
    putchar('\n');
    //-----Print the island-----
    return oss.str();
};



/*
std::ostream& operator<<(std::ostream& os, const tile& receivedTile){
    os << receivedTile.type;
    return os;
}
 */
