#ifndef _SHELL_SYSTEM_COMMAND_HPP_
#define _SHELL_SYSTEM_COMMAND_HPP_

class SystemCommand : public Command {
    private:
        char** getArgs(std::vector<std::string> tokens);
        
    public:
        SystemCommand(std::string cmd);
        void execute();
}

SystemCommand::SystemCommand(std::string cmd) : Command(cmd){ }

void SystemCommand::execute() {
    // Tokenize command string
    std::vector<std::string> tokens = Command::tokenizeStr(commandString, ' ');
    
    auto start = std::chrono::system_clock::now();
    
    if (fork()) //parent
    {
        int status;
        wait(&status);
    }
    else 
    {
        //   if child, execute the user's input as a command
        
        char **args = getArgs(tokens);
        execvp(args[0], args);
        
        // command not found, or similar error
        std::cerr << args[0] << " did something wrong\n";
        
        exit(1);
    }
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    childPtime += elapsed_seconds; //update latest child process exec time
}

//-------------------------------------------------------------------
//
//  Generate new character pointer array of arguments (tokens) from
//  a vectors of strings where each string is a token/arg. 
//  This char** is NULL terminated.
//
//-------------------------------------------------------------------
char** SystemCommand::getArgs(std::vector<std::string> tokens)
{
    //  args needs to have a length of one more than the number of tokens
    //  to allow for NULL termination of the args array
    int size = tokens.size();
    char** args = new char*[size+1];
    
    //  convert and add each token to the args char* array
    for(int i = 0; i < size; i++) args[i] = (char*)tokens[i].c_str();
    args[size] = (char*)NULL;
    
    return args;
}



#endif