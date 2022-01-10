#ifndef POOISLAND_INTERPRETER_H
#define POOISLAND_INTERPRETER_H

#include <iostream>
#include <string>
#include <sstream>

class Interpreter {
    // all messages overloaded are requiered to have either "ERROR:" or "SUCCESS:" at the beginning
    std::string msg;
public:
    Interpreter();
    void overload(std::string);
    std::string& overloadedMsg();
    std::string predefinedErrors(int& code);
    static std::string helpMe();
    static std::string showCredits();
};


#endif //POOISLAND_INTERPRETER_H
