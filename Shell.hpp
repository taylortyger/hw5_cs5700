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
        
}

#endif