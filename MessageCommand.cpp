#include "MessageCommand.hpp"

MessageCommand::MessageCommand(std::string cmd, Shell& shell, std::string message) : Command(cmd, shell){
    this->message = message;
}

void MessageCommand::execute() {
    std::cout << this->message << std::endl;
}

std::string MessageCommand::getMessage() {
    return message;
}