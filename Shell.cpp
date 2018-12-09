#include "Shell.hpp"

void Shell::executeCmd(std::string cmd);

bool runBuiltInCommands(std::vector<std::string> tokens);
        
char** getArgs(std::vector<std::string> tokens);

std::vector<std::string> tokenizeStr(std::string str, char delimiter);