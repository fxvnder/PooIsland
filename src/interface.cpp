#include "interface.h"
#include "interpreter.h"
#include "program.h"

interface::interface(gameData &game) : game(game){ }

void interface::plays(){
    std::string command;
    Interpreter interpreter;
    int msgCode;
    do {
        command.clear();
        do { // to prevent sending an empty string to treatCommand
            std::cout << "\nInsert a command. For help type 'help'\n> ";
            getline(std::cin, command);
        } while (command.empty());
        msgCode = game.treatCommand(command, interpreter);
        if (msgCode >= 0) { game.saveCommsVec(command); }
        std::cout << interpreter.predefinedErrors(msgCode) << std::endl;
    } while (msgCode != 0);
}

void interface::start() {
    welcome(); // goes to the function of the own class per default
    mainMenu(); // main menu yeah
}

bool interface::getNumber(int &x){
    std::string theInput;
    std::getline(std::cin, theInput);
    if(std::cin.fail() || std::cin.eof() || theInput.find_first_not_of("0123456789") != std::string::npos || theInput.empty()) {
        if( theInput.find_first_not_of("0123456789") == std::string::npos) {
            std::cin.clear();
        }
        return false;
    }
    x = std::stoi(theInput);
    return true;
}

void interface::welcome(){
    // my beautiful palm tree
    const char *welcome =
            "                   ****\n"
            "                 ********\n"
            "                **  ******\n"
            "                *   ******     ******\n"
            "            **      ******   *********\n"
            "           *  ****   ****  *****   ***\n"
            "                ***  ***  ***     ***\n"
            "                *************      **\n"
            " ____   ___    __**********____ _   *   ____  ____   ___   \n"
            "|    \\ /   \\  /   \\*******   _/| |     /    ||    \\ |   \\  \n"
            "|  o  )     ||     |H****H   \\_| |    |  o  ||  _  ||    \\ \n"
            "|   _/|  O  ||  O  |H   H\\__  || |___ |     ||  |  ||  D  |\n"
            "|  |  |     ||     |H-_-H/  \\ ||     ||  _  ||  |  ||     |\n"
            "|  |  |     ||     |H   H\\    ||     ||  |  ||  |  ||     |\n"
            "|__|   \\___/  \\___/ H-_-H\\____||_____||__|__||__|__||_____|";

    std::cout << welcome << "\nWelcome to PooIsland!" << std::endl;
}

std::string Interpreter::showCredits(){
    return R"(
                 "           %%%%%%%%%%%%                                                         \n"
                 "       %%%%%%%%%%%%%%%%%%%%                                                     \n"
                 "     %%%%%%%%%%%%%%%%%%%%%%%%                                                   \n"
                 "   #%%%%%%%%%%%    %%%%%%%%%%%        %%%%  %%%%%%%%%%   %%%%%%%%%   %%%%%%%%%  \n"
                 "  .%%%%%%%%%          %%%%%%%%%       %%%%  %%%%}       %%%____%%%% %%%%        \n"
                 "  %%%%%%%%%            %%%%%%%%%      %%%%      {%%%%%  %%%         %%%%        \n"
                 "  %%%%%%%%%            %%%%%%%%%      %%%%  #%%%%%%%%%   %%%%%%%%%   %%%%%%%%%. \n"
                 "  %%%%%%%%%            %%%%%%%%%                    2021/2022                   \n"
                 "  %%%%%%%%%            %%%%%%%%%                                                \n"
                 "  %%%%%%%%%            %%%%%%%%%      Made by: Joao 'FXVNDER' Oliveira\n"
                 "  %%%%%%%%%            %%%%%%%%%               Joao 'Yeshey' Almeida\n";
            )";
}

void interface::mainMenu() {
    bool success = false;
    int userInp;
    std::string filename;
    do {
        std::cout << "\nWould you like to play the game?\n1 - New Game\n2 - Show Credits\n9 - Exit\n > ";
        if ((!getNumber(userInp))){
            std::cout << " NaN\n";
            continue;
        }
        if (userInp == 1){
            success = true;
            newGame();
        } else if (userInp == 2) {
            std::cout << Interpreter::showCredits();
        } else if (userInp == 9) {
            exit(EXIT_SUCCESS);
        } else {
            std::cout << "\nWell, you probably said something wrong... Try out again." << std::endl;
        }
    } while (!success);
}

std::string Interpreter::helpMe() {
    return R"(
        >>> HELP <<<
        Welcome to PooIsland. These are the commands to learn how to play the game!
        >> EXEC <filename> -> executes saved file commands
        >> CONS <type> <line> <column> -> builds <type> in the coordinates
        >> UPGRD <line> <column> -> upgrades building in target tile
        >> LIGA <line> <column> -> coming soon
        >> DES <line> <column> -> destroys what's on X,Y
        >> MOVE <id> <line> <column> -> coming soon
        >> VENDE <type> <when> -> coming soon
        >>>> OR <<<<
        >> VENDE <line> <column> -> coming soon
        >> CONT <type> -> hires worker from <type>
        >> LIST (optional: <type> <column>) -> lists events/workers/etc.
        >> NEXT -> Skips to next day.
        >> SAVE -> saves game state to memory
        >> SAVECOMMANDS -> saves the commands written to a file
        >> LOAD -> loads game state from memory
        >> APAGA <name> -> deletes game state from memory
        >> CONFIG <filename> -> opens config saved file
		>> DEBCASH <value> -> coming soon (debug)
		>> DEBED <type> <line> <column> -> coming soon (debug)
		>> DEBKILL <id> -> coming soon (debug)
        >> HELP -> shows help with commands
        >> EXIT -> ends program
        )";
}

void interface::newGame() {
    int dim[2];
    bool success = false;

    // player chooses Island dimensions
    do{
        std::cout << "Welcome to PooIsland! Let's start your game!\nChoose the Island size(lines): 1/2\n > ";
        getNumber(dim[0]);
        std::cout << "Size(columns): 2/2\n > ";
        getNumber(dim[1]);
        if (dim[0] >= 3 && dim[0] <= 8 && dim[1] >= 3 && dim[1] <= 16){ // restrictions
            success = true;
        } else {
            std::cout << "\nInvalid data received, try again!\n" << std::endl;
        }
    } while (!success);
    game.createNewWorld(dim);
    gameCycle();
}

void interface::gameCycle(){
    do {
        std::cout << game.island().showInfoIsland() << std::endl;
        game.dawn();
        plays();
        game.dusk();
    } while (!game.over());
}