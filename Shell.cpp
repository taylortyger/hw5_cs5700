#include "Shell.hpp"

Shell::Shell() {
    timeToQuit = false;
    childPtime = std::chrono::nanoseconds::zero();
    commandFactory = CommandFactory();
}

void Shell::run() {
    // Shell loop
    while (!timeToQuit) 
    {
        char path[MAX_PATH_SIZE];
        getcwd(path, MAX_PATH_SIZE);
        
        //
        //Get user input
        std::cout << "[" << path <<"]: ";
        std::string cmd;
        std::getline(std::cin, cmd);
        
        if(cmd != "")
        {
            Command* command = getCommandFactory().newCommand(cmd, *this);
            if(command != nullptr){
                command->execute();
                childPtime += command->getChildPtime();
            }
            
            delete command;
        }
        
    }
}

void Shell::setTimeToQuit(bool timeToQuit) {
    this->timeToQuit = timeToQuit;
}

std::chrono::duration<double> Shell::getChildPtime() {
    return this->childPtime;
}

CommandFactory& Shell::getCommandFactory() {
    return this->commandFactory;
}
