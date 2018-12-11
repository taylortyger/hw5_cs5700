#ifndef _COMMAND_FACTORY_HPP_
#define _COMMAND_FACTORY_HPP_

#include "Command.hpp"

class Shell;


class CommandFactory {
    private:
        std::vector<std::string> historyBuffer;
        
    public:
        CommandFactory();
        Command* newCommand(std::string cmd, Shell& shell);
        std::vector<std::string> getHistoryBuffer();
        
};

#endif