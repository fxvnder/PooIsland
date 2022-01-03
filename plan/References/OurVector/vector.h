#ifndef VECTOR
#define VECTOR

#include <iostream>
#include <sstream>

namespace poo {
    template <class T> class vector {
        T * parr;
        int tam;
    public:
        vector(); // Constructor
        ~vector(); // Destructor
        vector(const vector & old); // Copy Constructor

        vector & operator=( /*const*/ vector /*&*/ outro);
        T & operator[](int index);

        void add(T obj);
        std::string display();
        int size();
    };
}

// to avoid linking issues, due to the template class
// with this, we can't add vector.cpp to the compiled files
#include "vector.cpp"

#endif // VECTOR