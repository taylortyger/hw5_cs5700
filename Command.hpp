#ifndef _SHELL_COMMAND_HPP_
#define _SHELL_COMMAND_HPP_

class Command {
    protected:
        std::chrono::duration<double> childPtime; // to keep total time executing child processes
        std::string cmd;
        Shell& shell;
        
    public:
        Command(std::string cmd, Shell& shell);
        std::chrono::duration<double> getChildPtime();
        
        static std::vector<std::string> tokenizeStr(std::string str, char delimiter);
        static char** getArgs(std::vector<std::string> tokens);
        
        virtual void execute() = 0;
}

Command::Command(std::string cmd, Shell& shell){
    this->cmd = cmd;
    this->childPtime = std::chrono::nanoseconds::zero();
    this->shell = shell;
}

std::chrono::duration<double> Command::getChildPtime() {
    return childPtime;
}


static std::vector<std::string> Command::tokenizeStr(std::string str, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream ss(str);
    std::string token;
    while(std::getline(ss, token, delimiter)) tokens.push_back(token);   
    return tokens;
}

//-------------------------------------------------------------------
//
//  Generate new character pointer array of arguments (tokens) from
//  a vectors of strings where each string is a token/arg. 
//  This char** is NULL terminated.
//
//-------------------------------------------------------------------
static char** Command::getArgs(std::vector<std::string> tokens)
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
