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
        void add();
        std::string display();
        int size();

    private:
    // implemented in header file due to added implementatin complexity when implementing a friend function of a template class outside the header
        friend std::ostream& operator<< ( std::ostream& out, const vector<T>& f){
            for (int i=0 ; i<f.tam ; ++i) {
                out << f.parr[i] << "\t";
            }
            out << std::endl;
            return out;
        }
    };
}

// to avoid linking issues, due to the template class
// with this, we can't add vector.cpp to the compiled files in CMakeLists
// to avoid this, we would make all the code of this class in the header file
#include "vector.cpp"

#endif // VECTOR