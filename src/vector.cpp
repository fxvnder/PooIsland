// this cpp file is included in the end of vector.h to avid linking issues with the template
// thus it shan't be added to the compiled files
#include "vector.h"

// Constructor
template <class T>
poo::vector<T>::vector() : tam(0), parr(nullptr){
    std::cout << "Constructor Called" << std::endl;
}

// Destructor
template <class T>
poo::vector<T>::~vector() {
    std::cout << "Destructor Called" << std::endl;
    //for (int i = 0; i < tam; i++){
    //    delete parr[i];
    //}
    delete []parr;
}

// Copy Constructor
template <class T>
poo::vector<T>::vector (const poo::vector<T> & old){  //vamos substitui-lo
    std::cout << "Copy Constructor Called" << std::endl;
    tam = old.tam;
    parr = new T[tam];
    for (int i = 0; i < tam; i++) {
        parr[i] = old.parr[i];
    }
}

// Operator= (made using Copy Constructor)
template <class T>
poo::vector<T> & poo::vector<T>::operator=( /*const*/ vector /*&*/ old){ //idioma swap
    std::cout << "Operator= Called" << std::endl;
    // the object old will die here
    std::swap (tam, old.tam);
    std::swap (parr, old.parr);
    return *this;
}

// Operator[]
template <class T>
T & poo::vector<T>::operator[](int index){
    if (index >= tam) throw 101;

    return parr[index];
}

// Operator<< implemented in header file

template <class T>
void poo::vector<T>::add(T obj){
    T * paux = new T [tam + 1];
    for (int i = 0; i < tam; ++i)
        paux[i]=parr[i];

    paux[tam] = obj;
    tam += 1;
    delete [] parr;
    parr = paux;
}

template <class T>  
void poo::vector<T>::add(){
    T * paux = new T [tam + 1];
    for (int i = 0; i < tam; ++i)
        paux[i]=parr[i];

    tam += 1;
    delete [] parr;
    parr = paux;
}

template <class T>
std::string poo::vector<T>::display(){
    std::ostringstream oss;
    for (int i=0 ; i<tam ; ++i) {
        oss << parr[i] << "\t";
    }
    oss << "|";
    return oss.str();
}

template <class T>
int poo::vector<T>::size(){
    return tam;
}