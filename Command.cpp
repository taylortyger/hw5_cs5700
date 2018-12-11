#include "Command.hpp"
#include "Shell.hpp"

Command::Command(std::string cmd, Shell& shell) : shell(shell){
    this->cmd = cmd;
    this->childPtime = std::chrono::nanoseconds::zero();
}

std::chrono::duration<double> Command::getChildPtime() {
    return childPtime;
}


std::vector<std::string> Command::tokenizeStr(std::string str, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream ss(str);
    std::string token;
    while(std::getline(ss, token, delimiter)){
        if(token != "") tokens.push_back(token);  
    } 
    return tokens;
}

//-------------------------------------------------------------------
//
//  Generate new character pointer array of arguments (tokens) from
//  a vectors of strings where each string is a token/arg. 
//  This char** is NULL terminated.
//
//-------------------------------------------------------------------
char** Command::getArgs(std::vector<std::string> tokens)
{
    //  args needs to have a length of one more than the number of tokens
    //  to allow for NULL termination of the args array
    int size = tokens.size();
    char** args = new char*[size+1];
    
    //  convert and add each token to the args char* array
    for(int i = 0; i < size; i++) args[i] = (char*)tokens[i].c_str();
    args[size] = (char*)NULL;
    
    return args;
}
