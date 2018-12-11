#ifndef _SHELL_PIPE_COMMAND_HPP_
#define _SHELL_PIPE_COMMAND_HPP_

#include "Command.hpp"

class PipeCommand : public Command {
        
    public:
        PipeCommand(std::string cmd, Shell& shell);
        void execute();
};


#endif
