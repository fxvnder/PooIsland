#ifndef POOISLAND_UTILS_H
#define POOISLAND_UTILS_H

int random (int low, int high);

namespace poo {
    template <typename T> class vectorClass{
        T* arr;
        int capacity;
        int current;
    public:
        vector();
        void push(T data);
        void push(T data, int index);
        T get(int index);
        void pop();
        int size();
        int getcapacity();
    };
    int doSomething(int x, int y);
}

#endif //POOISLAND_UTILS_H
