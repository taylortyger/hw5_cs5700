#ifndef _COMMAND_FACTORY_HPP_
#define _COMMAND_FACTORY_HPP_

class CommandFactory {
    protected:
        std::vector<std::string> historyBuffer;
        
    public:
        CommandFactory();
        Command newCommand(std::string commandString);
        
}

#endif