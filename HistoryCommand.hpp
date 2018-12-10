#ifndef _SHELL_HISTORY_COMMAND_HPP_
#define _SHELL_HISTORY_COMMAND_HPP_

class HistoryCommand : public Command {
    public:
        HistoryCommand(std::string cmd, Shell& shell);
        void execute();
}

HistoryCommand::HistoryCommand(std::string cmd, Shell& shell) : Command(cmd, shell){}

void HistoryCommand::execute() {
    
    std::vector<std::string> historyBuffer = shell.getCommandFactory().getHistoryBuffer();
    
    std::cout << "---  Command History  --- \n";
    for(unsigned i = 0; i < historyBuffer.size(); i++)
        std::cout << i+1 << " : " << historyBuffer[i] << std::endl;
}

#endif