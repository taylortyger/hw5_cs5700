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
    std::vector<std::string> tokens = Command::tokenizeStr(cmd, ' ');
    
    //create a previous command from history buffer
    if(tokens[0] == "^"){
        unsigned indx;
        std::istringstream ss(tokens[1]);
        ss >> indx;
        if(indx > historyBuffer.size()) {
            //Probably be better to make a MessageCommand that takes in a message string,
            // from which execute() simply prints out the message. 
            std::string msg = "You have not used " + indx + " command(s) yet.\n";
            return MessageCommand(cmd, shell, msg);
            
        } else {
            std::string cmdToExecute = historyBuffer[(int)indx-1];
            return newCommand(cmdToExecute, shell);
        }
    }
    //built in command which displays history of commands
    else if(tokens[0] == "history") {
        historyBuffer.push_back(cmd);
        return HistoryCommand(cmd, shell);
    }
    //built in command which displays total time running child processes
    else if(tokens[0] == "ptime") {
        historyBuffer.push_back(cmd);
        return PTimeCommand(cmd, shell);
    }
    //built in command which changes directory
    else if(tokens[0] == "cd") {
        historyBuffer.push_back(cmd);
        return CdCommand(cmd, shell);
    }
    //Pipeline of commands (Note: DOES NOT SUPPORT BUILT IN COMMANDS)
    else if(Command::tokenizeStr(cmd, '|').size() > 1) {
        historyBuffer.push_back(cmd);
        return PipeCommand(cmd, shell);
    } 
    // If not pipeline, and not built in command, run as system command
    else {
        historyBuffer.push_back(cmd);
        return SystemCommand(cmd, shell);
    }
}

std::vector<std::string> CommandFactory::getHistoryBuffer() {
    return historyBuffer;
}

#endif