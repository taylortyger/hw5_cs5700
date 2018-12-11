#include <sys/wait.h>
#include <iostream>
#include <unistd.h>
#include <vector>
#include <sstream> 
#include <chrono>
#include <ctime>
#include <iomanip>
#include "Shell.hpp"
#include "Test.hpp"

int main(void) 
{
    Shell shell = Shell();
    shell.run();
    //Test::runTests();
    return 0;
}