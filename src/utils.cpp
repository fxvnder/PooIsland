#include "utils.h"

int random (int low, int high) {
    if (low > high) return high;
    std::random_device rd;
    std::default_random_engine e{rd()};
    std::uniform_int_distribution<int> dist{low, high};
    return dist(e);
}

std::string strToLower(std::string str){
    std::for_each(str.begin(), str.end(), [](char & c) {
        c = ::tolower(c);
    });
    return str;
}
