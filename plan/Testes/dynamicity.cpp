#include <iostream>
#include <sstream>

using namespace std;


class boy{
    int age_var;
public:
    boy(int a) : age_var(a){};
    int age(){
        return age_var;
    }

};

int main(){
    boy mario(4);
    auto p = new boy(3);
    cout << p->age();
}