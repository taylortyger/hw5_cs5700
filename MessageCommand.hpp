#ifndef _SHELL_MESSAGE_COMMAND_HPP_
#define _SHELL_MESSAGE_COMMAND_HPP_

#include "Command.hpp"

class MessageCommand : public Command {
    private: 
        std::string message;
    public:
        MessageCommand(std::string cmd, Shell& shell, std::string message);
        void execute();
};

#endif