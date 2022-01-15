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

    // commands
    static std::string showCredits();

    // help
    static std::string helpMe();

    static std::string helpExec();
    static std::string helpCons();
    static std::string helpUpgrd();
    static std::string helpLiga();
    static std::string helpDes();
    static std::string helpMove();
    static std::string helpVende();
    static std::string helpCont();
    static std::string helpList();
    static std::string helpNext();
    static std::string helpSave();
    static std::string helpSavecommands();
    static std::string helpLoad();
    static std::string helpApaga();
    static std::string helpSavescreen();
    static std::string helpConfig();
    static std::string helpDebcash();
    static std::string helpDebed();
    static std::string helpDebkill();
    static std::string helpHelp();
    static std::string helpExit();
};


#endif //POOISLAND_INTERPRETER_H
