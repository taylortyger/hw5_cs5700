#ifndef _SHELL_COMMAND_HPP_
#define _SHELL_COMMAND_HPP_

class Command {
    protected:
        std::chrono::duration<double> childPtime; // to keep total time executing child processes
        std::string commandString;
        
    public:
        Command(std::string cmd);
        virtual void execute();
        static std::vector<std::string> tokenizeStr(std::string str, char delimiter);
        std::chrono::duration<double> getChildPtime();
}

Command::Command(std::string cmd){
    commandString = cmd;
    childPtime = std::chrono::nanoseconds::zero();
}

static std::vector<std::string> Command::tokenizeStr(std::string str, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream ss(str);
    std::string token;
    while(std::getline(ss, token, delimiter)) tokens.push_back(token);   
    return tokens;
}

std::chrono::duration<double> Command::getChildPtime() {
    return childPtime;
}



#endif