#include "utils.h"
#include "program.h"
#include "interface.h"
#include "interpreter.h"

interface::interface(gameData &game) : game(game){ }

void interface::plays(){
    std::string command;
    Interpreter interpreter;
    int msgCode;
    auto start = std::chrono::system_clock::now();
    do {
        command.clear();
        do { // to prevent sending an empty string to treatCommand
            std::cout << "\nInsert a command. For help type 'help'\n> ";
            getline(std::cin, command);
        } while (command.empty());

        // see time it took since start of plays
        auto end = std::chrono::system_clock::now();
        std::chrono::duration<double> elapsed_seconds = end-start;

        msgCode = game.treatCommand(command, interpreter, elapsed_seconds.count());
        if (msgCode >= 0) { game.saveCommsVec(command); } // if successful command, record it
        std::cout << interpreter.predefinedErrors(msgCode) << std::endl;

        if (elapsed_seconds.count() > DAYTIME){
            msgCode = 0; // after making commands for over DAYTIME seconds, a new day will automatically start
            std::cout << "The day has ended!" << std::endl;
        }
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
        --- FOR ADVANCED HELP TYPE "HELP X", BEING X = COMMANDNAME
        >> EXEC <filename> -> executes saved file commands
        >> CONS <type> <line> <column> -> builds <type> in the coordinates
        >> UPGRD <line> <column> -> upgrades building in target tile
        >> LIGA <line> <column> -> turns on building on <line> <column>
        >> DES <line> <column> -> turns off building on <line> <column>
        >> MOVE <id> <line> <column> -> moves worker with <id> to <line> <column>
        >> VENDE <type> <quantity> -> sells <quantity> of <type> resource.
        >>>> OR <<<<
        >> VENDE <line> <column> -> sells whatever is on <line> <column>
        >> CONT <type> -> hires worker from <type>
        >> LIST (optional: <type> <column>) -> lists events/workers/etc.
        >> NEXT -> Skips to next day.
        >> SAVECOMMANDS <filename> -> saves the commands written to a file
        >> SAVE <savename> -> saves game state to memory
        >> LOAD <savename> -> loads game state from memory
        >> APAGA <name> -> deletes game state from memory
        >> SAVESCREEN -> shows saved games
        >> CONFIG <filename> -> opens config saved file
		>> DEBCASH <value> -> adds <value> money (debug)
		>> DEBED <type> <line> <column> -> adds building of <type> to <line> <column> with no cost (debug)
		>> DEBKILL <id> -> deletes player with <id> (debug)
        >> HELP (optional: <command>) -> shows help with commands
        >> EXIT -> ends program
        )";
}

std::string Interpreter::helpExec(){
    return R"(
        >> EXEC FILENAME
        >> EXECUTES THE COMMANDS INSIDE A FILE.
    )";
}
std::string Interpreter::helpCons(){
    return R"(
        >> CONS <TYPE> <LINE> <COLUMN>
        >> BUILDS BUILDING <TYPE> IN <LINE> <COLUMN>
        >> BUILDINGS:
        > MNF = MINA DE FERRO
Permite obter ferro. Pode ser construída gastando 10 vigas de madeira, em que cada viga pode
ser substituída por 10 €. Produz 2 Kg de ferro por dia. Pode ser melhorada até ao nível 5 em que cada nível
aumenta a produção em 1 kg de ferro por dia. Cada nível de melhoramento exige 15 € e 1 viga de madeira
(não substituível por €). A mina apenas produz se existir um mineiro na zona em que a mina se encontra. Em
cada dia a mina tem 15% de probabilidade de desabar. A mina de ferro armazena até 100 kg de ferro, mais 10
Kg por cada nível adicional. Depois disso, pára de produzir.
        > MNC = MINA DE CARVAO
Permite obter carvão. Pode ser construída gastando 10 vigas de madeira, em que cada viga
pode ser substituída por 10 €. Produz 2 Kg de carvão por dia. Pode ser melhorada até ao nível 5 em que cada
nível aumenta a produção em 1 kg de carvão por dia. Cada nível de melhoramento exige 10 € e 1 viga de
madeira (não substituível por €). A mina apenas produz se existir um mineiro na zona em que a mina se
encontra. Em cada dia a mina tem 10% de probabilidade de desabar. A mina de carvão armazena até 100 kg
de carvão, mais 10 Kg por cada nível adicional. Depois disso, pára de produzir.
        > ELEC = CENTRAL ELETRICA
Central elétrica de biomassa: Queima madeira, produzindo carvão e eletricidade. A central elétrica transforma
1kg de madeira em 1 kg de carvão mais 1 KWh de eletricidade por dia, desde que se encontre um operário na
zona em que se encontra. A central pode armazenar o carvão produzido até 100 kg de carvão. A eletricidade
ficará armazenada numa bateria que se encontre numa zona adjacente, caso contrário perde-se. Para
funcionar, a central elétrica tem que estar numa zona adjacente a uma zona do tipo floresta, sendo a madeira
obtida a partir da madeira que tenha sido cortada e depositada nessa zona de floresta. Custa 15 €.
        > BAT = BATERIA
Bateria: é um edifício que consiste num enorme bloco de lítio que armazena eletricidade. Tem capacidade de
100 KWh. Custa 10 € e 10 vigas. Adquire automaticamente a energia produzida nas centrais elétricas que
estejam colocadas em zonas adjacentes. Pode ser melhorado até ao nível 5 por mais 5 € cada nível
        > FUN = FUNDICAO
Permite obter aço a partir de ferro e carvão. Para funcionar é necessário que a zona em que se
encontre seja adjacente a uma zona que tenha uma mina de ferro e a uma mina de carvão ou a uma central
elétrica (por causa do carvão). Precisa também de ter um operário na sua zona. Custa 10 €.
        > SARR = SARRACAO
Serracao.
    )";
}
std::string Interpreter::helpUpgrd(){
    return R"(
        >> UPGRD <LINE> <COLUMN>
        >> UPGRADES BUILDING LOCATED IN <LINE> <COLUMN>
        >> AVAILABLE FOR:
        > MINA DE FERRO (UP TO LEVEL 5)
        > MINA DE CARVAO (UP TO LEVEL 5)
        > BATERIA (UP TO LEVEL 5)
    )";
}
std::string Interpreter::helpLiga(){
    return R"(
        >> LIGA <LINE> <COLUMN>
        >> TURNS ON BUILDING LOCATED IN <LINE> <COLUMN>
    )";
}
std::string Interpreter::helpDes(){
    return R"(
        >> DESLIGA <LINE> <COLUMN>
        >> TURNS OFF BUILDING LOCATED IN <LINE> <COLUMN>
    )";
}
std::string Interpreter::helpMove(){
    return R"(
        >> MOVE <ID> <LINE> <COLUMN>
        >> MOVES WORKER WITH <WORKER_ID> TO <LINE> <COLUMN>
    )";
}
std::string Interpreter::helpVende(){
    return R"(
        >> VENDE <TYPE> <QUANTITY>
        OR
        >> VENDE <LINE> <COLUMN>

        >> SELLS <QUANTITY> OF <TYPE> RESOURCE.
        OR
        >> SELLS WHATEVER IS ON <LINE> <COLUMN>

    )";
}
std::string Interpreter::helpCont(){
    return R"(
        >> CONT <TYPE>
        >> HIRES WORKER FROM <TYPE>
    )";
}
std::string Interpreter::helpList(){
    return R"(
        >> LIST
        OR
        >> LIST <TYPE> <COLUMN>

        >> LISTS THE ENTIRE ISLAND
        OR
        >> LISTS A SPECIFIC TILE
    )";
}
std::string Interpreter::helpNext(){
    return R"(
        >> NEXT
        >> SKIPS TO THE NEXT DAY.
    )";
}
std::string Interpreter::helpSave(){
    return R"(
        >> SAVE <savename>
        >> SAVES GAME STATE TO MEMORY
    )";
}
std::string Interpreter::helpSavecommands(){
    return R"(
        >> SAVECOMMANDS <filename>
        >> SAVES COMMAND HISTORY INTO <filename>
        >> CAN BE OPENED WITH EXEC <filename>
    )";
}
std::string Interpreter::helpLoad(){
    return R"(
        >> STUFF
    )";
}
std::string Interpreter::helpApaga(){
    return R"(
        >> STUFF
    )";
}
std::string Interpreter::helpSavescreen(){
    return R"(
        >> STUFF
    )";
}
std::string Interpreter::helpConfig(){
    return R"(
        >> STUFF
    )";
}
std::string Interpreter::helpDebcash(){
    return R"(
        >> STUFF
    )";
}
std::string Interpreter::helpDebed(){
    return R"(
        >> STUFF
    )";
}
std::string Interpreter::helpDebkill(){
    return R"(
        >> STUFF
    )";
}
std::string Interpreter::helpHelp(){
    return R"(
        >> STUFF
    )";
}
std::string Interpreter::helpExit(){
    return R"(
        >> STUFF
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
        game.island().incRound();
        std::cout << game.island().showInfoIsland(0) << std::endl;
        game.dawn();
        plays();
        game.dusk();
    } while (!game.over());
}