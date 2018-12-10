#ifndef _SHELL_SYSTEM_COMMAND_HPP_
#define _SHELL_SYSTEM_COMMAND_HPP_

class SystemCommand : public Command {
    public:
        SystemCommand(std::string cmd, Shell& shell);
        void execute();
}

SystemCommand::SystemCommand(std::string cmd, Shell& shell) : Command(cmd, shell){ }

void SystemCommand::execute() {
    // Tokenize command string
    std::vector<std::string> tokens = Command::tokenizeStr(cmd, ' ');
    
    auto start = std::chrono::system_clock::now();
    
    if (fork()) //parent
    {
        int status;
        wait(&status);
    }
    else 
    {
        //   if child, execute the user's input as a command
        
        char **args = Command::getArgs(tokens);
        execvp(args[0], args);
        
        // command not found, or similar error
        std::cerr << args[0] << " did something wrong\n";
        
        exit(1);
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    childPtime += elapsed_seconds; //update latest child process exec time
}


#endif