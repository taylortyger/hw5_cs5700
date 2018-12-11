#ifndef _SHELL_SYSTEM_COMMAND_HPP_
#define _SHELL_SYSTEM_COMMAND_HPP_

#include "Command.hpp"

class SystemCommand : public Command {
    public:
        SystemCommand(std::string cmd, Shell& shell);
        void execute();
};

#endif