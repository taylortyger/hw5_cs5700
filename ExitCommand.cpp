#include "ExitCommand.hpp"
#include "Shell.hpp"

ExitCommand::ExitCommand(std::string cmd, Shell& shell) : Command(cmd, shell){}

void ExitCommand::execute() {
    shell.setTimeToQuit(true);
}
