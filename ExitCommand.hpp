#ifndef _SHELL_EXIT_COMMAND_HPP_
#define _SHELL_EXIT_COMMAND_HPP_

class ExitCommand : public Command {
    public:
        ExitCommand(std::string cmd, Shell& shell);
        void execute();
}

ExitCommand::ExitCommand(std::string cmd, Shell& shell) : Command(cmd, shell){}

void ExitCommand::execute() {
    shell.setTimeToQuit(true);
}

#endif