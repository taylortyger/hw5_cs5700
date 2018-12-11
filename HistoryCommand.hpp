#ifndef _SHELL_HISTORY_COMMAND_HPP_
#define _SHELL_HISTORY_COMMAND_HPP_

#include "Command.hpp"

class HistoryCommand : public Command {
    public:
        HistoryCommand(std::string cmd, Shell& shell);
        void execute();
};

#endif