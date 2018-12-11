#include "HistoryCommand.hpp"
#include "Shell.hpp"

HistoryCommand::HistoryCommand(std::string cmd, Shell& shell) : Command(cmd, shell){}

void HistoryCommand::execute() {
    
    std::vector<std::string> historyBuffer = shell.getCommandFactory().getHistoryBuffer();
    
    std::cout << "---  Command History  --- \n";
    for(unsigned i = 0; i < historyBuffer.size(); i++)
        std::cout << i+1 << " : " << historyBuffer[i] << std::endl;
}
