#include "vector.h"

 // cpp
template <class T>
poo::mypair<T>::mypair (T first, T second){
    values[0]=first; values[1]=second;
    std::cout << first << " | " << second << std::endl;
}