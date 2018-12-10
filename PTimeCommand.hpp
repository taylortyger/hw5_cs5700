#ifndef _SHELL_PTIME_COMMAND_HPP_
#define _SHELL_PTIME_COMMAND_HPP_

class PTimeCommand : public Command {
    public:
        PTimeCommand(std::string cmd, Shell& shell);
        void execute();
}

PTimeCommand::PTimeCommand(std::string cmd, Shell& shell) : Command(cmd, shell){}

void PTimeCommand::execute() {
    std::cout << "Time spent executing child processes: ";
    std::cout << std::fixed <<  std::setprecision(4) << (double)shell.getChildPtime().count() << "s\n";
}

#endif