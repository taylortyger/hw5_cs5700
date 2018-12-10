#ifndef _MY_SHELL_HPP_
#define _MY_SHELL_HPP_

class Shell {
    private:
        //data members
        const int MAX_PATH_SIZE = 256;
        bool timeToQuit;
        std::chrono::duration<double> childPtime; // to keep total time executing child processes
        CommandFactory commandFactory;
        
    public:
        Shell();
        void run();
        void setTimeToQuit(bool);
        std::chrono::duration<double> getChildPtime();
        CommandFactory& getCommandFactory();
        
}

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
            Command command = getCommandFactory().newCommand(cmd, *this);
            if(command != NULL){
                command.execute();
                childPtime += command.getChildPtime();
            }
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



#endif