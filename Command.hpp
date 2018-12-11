#ifndef _SHELL_COMMAND_HPP_
#define _SHELL_COMMAND_HPP_

#include <sys/wait.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <sstream> 
#include <chrono>
#include <ctime>
#include <iomanip>

class Shell;

class Command {
    protected:
        std::chrono::duration<double> childPtime; // to keep total time executing child processes
        std::string cmd;
        Shell& shell;
        
    public:
        Command(std::string cmd, Shell& shell);
        std::chrono::duration<double> getChildPtime();
        std::string getCmd();
        
        static std::vector<std::string> tokenizeStr(std::string str, char delimiter);
        static char** getArgs(std::vector<std::string> tokens);
        
        virtual void execute() = 0;
};


#endif
