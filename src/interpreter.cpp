#include "interpreter.h"

Interpreter::Interpreter() : msg("") { }

void Interpreter::overload(std::string str) {
    msg = str;
}

std::string& Interpreter::overloadedMsg(){
    return msg;
}

std::string Interpreter::predefinedErrors(int& code) {
    static std::string overloaded; // For very specific error codes.

    // negative codes indicate errors, positive ones indicate success.

    switch (code) {
        case (0): return "Continuing...";
        case (1): return "File opened with success!";
        case (2): return Interpreter::showCredits();
        case (3): return Interpreter::helpMe();
        case (5): return "Turned Off";
        case (6): return "Turned On";
        case (-1): return "Error opening file!";
        case (-2): return "ERROR: Invalid number of arguments. Use 'help' for help.";
        case (-3): return "Target zone coordinates fall outside the Island!";
        case (-4): return "Expected digits";
        case (-5): return "Malformed command, type 'help' for a list of available commands";
        case (-6): return "Wrong filename or file nonexistent";
        case (-7): return "No building in target Tile";
        case (-8): return "Building already off";
        case (-9) : return "Building already on";
        case (-10) : return "No worker was found with that ID!";
        case (-11) : return "File saved!";
        case (-404): return "Something wrong happened!";

        case (111): //overloaded message
            if (msg.find("ERROR") != std::string::npos) { // first word is "ERROR:"
                code = -111;
                return msg;
            } else if (msg.find("SUCCESS") != std::string::npos) { // first word is "SUCCESS:"
                return msg;
            } else {
                std::ostringstream oss;
                oss << "(Unable to identify SUCCESS or ERROR)" << std::endl << msg;
                return oss.str();
            }

        default:
            return "Code not found";
    }
}