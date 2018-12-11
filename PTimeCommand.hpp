#ifndef _SHELL_PTIME_COMMAND_HPP_
#define _SHELL_PTIME_COMMAND_HPP_

#include "Command.hpp"

class PTimeCommand : public Command {
    public:
        PTimeCommand(std::string cmd, Shell& shell);
        void execute();
};

#endif
