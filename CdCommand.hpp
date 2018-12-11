#ifndef _SHELL_CHANGE_DIRECTORY_COMMAND_HPP_
#define _SHELL_CHANGE_DIRECTORY_COMMAND_HPP_

#include "Command.hpp"

class CdCommand : public Command {
        
    public:
        CdCommand(std::string cmd, Shell& shell);
        void execute();
};

#endif
