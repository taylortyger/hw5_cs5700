#include "CommandFactory.hpp"
#include "MessageCommand.hpp"
#include "HistoryCommand.hpp"
#include "PTimeCommand.hpp"
#include "CdCommand.hpp"
#include "PipeCommand.hpp"
#include "SystemCommand.hpp"
#include "ExitCommand.hpp"

CommandFactory::CommandFactory() {}

Command* CommandFactory::newCommand(std::string cmd, Shell& shell) {
    std::vector<std::string> tokens = Command::tokenizeStr(cmd, ' ');
    
    Command* command = nullptr;
    
    //create a previous command from history buffer
    if(tokens[0] == "^"){
        unsigned indx;
        std::istringstream ss(tokens[1]);
        ss >> indx;
        if(indx > historyBuffer.size()) {
            //Probably be better to make a MessageCommand that takes in a message string,
            // from which execute() simply prints out the message. 
            std::string msg = "You have not used ";
            msg += indx +  " command(s) yet.\n";
            command = new MessageCommand(cmd, shell, msg);
            return command;
            
        } else {
            std::string cmdToExecute = historyBuffer[(int)indx-1];
            return newCommand(cmdToExecute, shell);
        }
    }
    //built in command which displays history of commands
    else if(tokens[0] == "history") {
        historyBuffer.push_back(cmd);
        command = new HistoryCommand(cmd, shell);
        return command;
    }
    //built in command which displays total time running child processes
    else if(tokens[0] == "ptime") {
        historyBuffer.push_back(cmd);
        command = new PTimeCommand(cmd, shell);
        return command;
    }
    //built in command which changes directory
    else if(tokens[0] == "cd") {
        historyBuffer.push_back(cmd);
        command = new CdCommand(cmd, shell);
        return command;
    }
    else if(tokens[0] == "exit") {
        historyBuffer.push_back(cmd);
        command = new ExitCommand(cmd, shell);
        return command;
    }
    //Pipeline of commands (Note: DOES NOT SUPPORT BUILT IN COMMANDS)
    else if(Command::tokenizeStr(cmd, '|').size() > 1) {
        historyBuffer.push_back(cmd);
        command = new PipeCommand(cmd, shell);
        return command;
    } 
    // If not pipeline, and not built in command, run as system command
    else {
        historyBuffer.push_back(cmd);
        command = new SystemCommand(cmd, shell);
        return command;
    }
}

std::vector<std::string> CommandFactory::getHistoryBuffer() {
    return historyBuffer;
}