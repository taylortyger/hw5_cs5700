#ifndef _SHELL_CHANGE_DIRECTORY_COMMAND_HPP_
#define _SHELL_CHANGE_DIRECTORY_COMMAND_HPP_

class CdCommand : public Command {
        
    public:
        CdCommand(std::string cmd, Shell& shell);
        void execute();
}

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

#endif