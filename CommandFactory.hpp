#ifndef _COMMAND_FACTORY_HPP_
#define _COMMAND_FACTORY_HPP_

class CommandFactory {
    private:
        std::vector<std::string> historyBuffer;
        
    public:
        CommandFactory();
        Command newCommand(std::string cmd, Shell& shell);
        std::vector<std::string> getHistoryBuffer();
        
}

CommandFactory::CommandFactory() {}

Command CommandFactory::newCommand(std::string cmd, Shell& shell) {
    //Check if cmd string is pipeline
    if(tokenizeStr(cmd, '|').size() > 1) {
        
    } 
}

std::vector<std::string> CommandFactory::getHistoryBuffer() {
    return historyBuffer;
}

#endif