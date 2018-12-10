#ifndef _SHELL_MESSAGE_COMMAND_HPP_
#define _SHELL_MESSAGE_COMMAND_HPP_

class MessageCommand : public Command {
    private: 
        std::string message;
    public:
        MessageCommand(std::string cmd, Shell& shell, std::string message);
        void execute();
}

HistoryCommand::HistoryCommand(std::string cmd, Shell& shell, std::string message) : Command(cmd, shell){
    this->message = message;
}

void HistoryCommand::execute() {
    std::cout << this->message << std::endl;
}

#endif