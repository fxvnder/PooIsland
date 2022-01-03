#ifndef POOISLAND_UTILS_H
#define POOISLAND_UTILS_H

int random (int low, int high);

// header
/*
namespace poo {
    template <class T>
    class vector {
        T* arr;
        int quant;
    public:
        vector ();
        void getmax(); 
    };
}
*/

/*
namespace poo2{
    template <class T>
    class mypair2 {
        T values [2];
    public:
        mypair2 (T first, T second){
            values[0]=first; values[1]=second;
        }
        void saysike(){
            int p = 1;
        }
    };
}*/

/*
namespace poo {
    // Inspect better:
    // https://www.learncpp.com/cpp-tutorial/user-defined-namespaces-and-the-scope-resolution-operator/
    // https://www.geeksforgeeks.org/how-to-implement-our-own-vector-class-in-c/

    template <typename T> class vector{
        // arr is the integer pointer
        // which stores the address of our vector
        T* arr;

        // capacity is the total storage
        // capacity of the vector
        int capacity;

        // current is the number of elements
        // currently present in the vector
        int current;

    public:
        vectorClass();
        void push(T data);
        void push(T data, int index);
        T get(int index);
        void pop();
        int size();
        int getcapacity();
    };
    int doSomething(int x, int y);
}

 */
#endif //POOISLAND_UTILS_H
