#include "utils.h"
#include <random>

using namespace std;

int random (int low, int high) {
    if (low > high) return high;
    std::random_device rd;
    std::default_random_engine e{rd()};
    std::uniform_int_distribution<int> dist{low, high};
    return dist(e);
}

 // cpp

template <class T>
void poo::vector<T>::getmax (){
  int retval;
}

/*
template <class T>
class mypair {
    T values [2];
public:
    mypair (T first, T second){
        values[0]=first; values[1]=second;
    }
};
*/

/*
        poo::vector<int>::vectorClass(){

        }

        // Default constructor to initialise
        // an initial capacity of 1 element and
        // allocating storage using dynamic allocation
        vectorClass(){
            arr = new T[1];
            capacity = 1;
            current = 0;
        }
        // Function to add an element at the last
        void push(T data){
            // if the number of elements is equal to the
            // capacity, that means we don't have space to
            // accommodate more elements. We need to double the
            // capacity
            if (current == capacity) {
                T* temp = new T[2 * capacity];

                // copying old array elements to new array
                for (int i = 0; i < capacity; i++) {
                    temp[i] = arr[i];
                }

                // deleting previous array
                delete[] arr;
                capacity *= 2;
                arr = temp;
            }
            // Inserting data
            arr[current] = data;
            current++;
        }

        // function to add element at any index
        void push(T data, int index){
            // if index is equal to capacity then this
            // function is same as push defined above
            if (index == capacity)
                push(data);
            else
                arr[index] = data;
        }
        // function to extract element at any index
        T get(int index){
            // if index is within the range
            if (index < current)
                return arr[index];
        }
        // function to delete last element
        void pop() { current--; }

        // function to get size of the vector
        int size() { return current; }

        // function to get capacity of the vector
        int getcapacity() { return capacity; }

        // function to print array elements

        void print(){
            for (int i = 0; i < current; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }

    int doSomething(int x, int y){
        return x + y;
    }
}
*/
