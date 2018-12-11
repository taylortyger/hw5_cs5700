#include "CdCommand.hpp"

CdCommand::CdCommand(std::string cmd, Shell& shell) : Command(cmd, shell){}

void CdCommand::execute() {
    // Tokenize command string
    std::vector<std::string> tokens = Command::tokenizeStr(cmd, ' ');
    
    if(tokens.size() < 2) std::cout << "No arguments supplied. 'cd' requires a path to a directory.\n";
    else
    {
        if(chdir(tokens[1].c_str())==-1)
        {
            std::cout << "Error: Could not change directory to '" << tokens[1] << "'.\n";
        }
    }
    
}
