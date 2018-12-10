#ifndef _SHELL_HISTORY_COMMAND_HPP_
#define _SHELL_HISTORY_COMMAND_HPP_

class HistoryCommand : public Command {
    private:
        std::vector<std::string>& historyBuffer;
        
    public:
        HistoryCommand(std::string cmd, std::vector<std::string>& historyBuffer);
        void execute();
}

HistoryCommand::HistoryCommand(std::string cmd, std::vector<std::string>& historyBuffer) : Command(cmd){
    historyBuffer = historyBuffer;
}

void HistoryCommand::execute() {
    std::cout << "---  Command History  --- \n";
    for(unsigned i = 0; i < historyBuffer.size(); i++)
        std::cout << i+1 << " : " << historyBuffer[i] << std::endl;
}

#endif