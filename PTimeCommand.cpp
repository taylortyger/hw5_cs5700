#include "PTimeCommand.hpp"

#include "Shell.hpp"

PTimeCommand::PTimeCommand(std::string cmd, Shell& shell) : Command(cmd, shell){}

void PTimeCommand::execute() {
    std::cout << "Time spent executing child processes: ";
    std::cout << std::fixed <<  std::setprecision(4) << (double)shell.getChildPtime().count() << "s\n";
}
