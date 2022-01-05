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
        friend std::ostream& operator<< ( std::ostream& out, const vector<T>& f){
            std::cout << "Operator<< Called ";
            for (int i=0 ; i<f.tam ; ++i) {
                out << f.parr[i] << "\t";
            }
            out << std::endl;
            return out;
        }
    };
/*
    template <class T, typename std::enable_if<std::is_enum<T>::value>::type* = nullptr>
    // https://stackoverflow.com/questions/17192694/templatized-ostream-overload-ambiguity-error-basic-ostreamchar-vs-const-char
    // in a case like `return out << "a1";` it MUST used std::operator<<, no other viable overload of the operator is found!
    // 
    std::ostream &operator<< (std::ostream &out, const poo::vector<T> & f);
    */
}

// to avoid linking issues, due to the template class
// with this, we can't add vector.cpp to the compiled files
// to avoid this, we would make all the code of this class in the header file
#include "vector.cpp"

#endif // VECTOR