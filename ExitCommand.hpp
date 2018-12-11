#ifndef _SHELL_EXIT_COMMAND_HPP_
#define _SHELL_EXIT_COMMAND_HPP_

#include "Command.hpp"

class ExitCommand : public Command {
    public:
        ExitCommand(std::string cmd, Shell& shell);
        void execute();
};

#endif
