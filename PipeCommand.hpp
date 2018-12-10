#ifndef _SHELL_PIPE_COMMAND_HPP_
#define _SHELL_PIPE_COMMAND_HPP_

class PipeCommand : public Command {
        
    public:
        PipeCommand(std::string cmd);
        void execute();
}

PipeCommand::PipeCommand(std::string cmd) : Command(cmd){}

void PipeCommand::execute() {
    //generate vector of command strings in pipeline delimited by '|'
    std::vector<std::string> commands = tokenizeStr(commandString, '|');
    
    //generate a token vector for each command string
    std::vector<std::vector<std::string>> tkns;
    for(unsigned int i=0; i < commands.size(); i++)
        tkns.push_back(tokenizeStr(commands[i], ' '));
        
    const int READ = 0;
    const int WRITE = 1;
    const int NUM_COMMANDS = tkns.size(); // n cmds
    const int NUM_PIPES = tkns.size()-1;  //need n-1 pipes for n cmds
    
    //create n-1 pipes
    int pipes[NUM_PIPES][2]; // array of pipes
    for(int i = 0; i < NUM_PIPES; i++) pipe(pipes[i]);
    
    auto start = std::chrono::system_clock::now(); // time child procs
    
    //Run each cmd in it's own child proc, sending i/o to correct fd
    for(int i = 0 ; i < NUM_COMMANDS; i++)
    {
        if(fork()==0)
        {
            //Keep track of which pipes have which pipe end open
            int openWritePipe = -1; //-1 == none in use
            int openReadPipe = -1;  //-1 == none in use
            
            //set up file descriptors for each command
            if(i==0)
            {
                dup2(pipes[i][WRITE], STDOUT_FILENO);
                openWritePipe = i;
            }
            else if (i == NUM_COMMANDS-1)
            {
                dup2(pipes[i-1][READ], STDIN_FILENO);
                openReadPipe = i-1;
            }
            else 
            {
                dup2(pipes[i-1][READ], STDIN_FILENO);
                dup2(pipes[i][WRITE], STDOUT_FILENO);
                openWritePipe = i;
                openReadPipe = i-1;
            }
            
            //close all pipe ends not used by this child process
            for(int i = 0; i < NUM_PIPES; i++)
            {
                if (i != openReadPipe ) close(pipes[i][READ]);
                if (i != openWritePipe) close(pipes[i][WRITE]);
            }
            
            // attempt to run command via execvp
            char **args = Command::getArgs(tkns[i]);
            if(execvp(args[0], args) < 0)
            {
                std::cerr << args[0] << " did something wrong\n";
                exit(1);
            }
        }
    }
    
    //close all pipe ends in the parent process
    for(unsigned int i = 0; i < tkns.size()-1; i++)
    {
        close(pipes[i][READ]);
        close(pipes[i][WRITE]);
    }
    
    //wait until all cmds in pipeline finish executing
    int wstatus;
    int kids = NUM_COMMANDS;
    while (kids > 0) 
    {
        pid_t childID = waitpid(-1, &wstatus, 0);
        if(wstatus != 0)
            std::cout << "Child proc " << childID << " exited with status "<< wstatus << std::endl;
        kids--;
    }
    
    // finished waiting for child procs; update child process times
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    childPtime += elapsed_seconds;
}

#endif