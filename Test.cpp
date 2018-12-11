#include "Shell.hpp"
#include "CommandFactory.hpp"
#include "CdCommand.hpp"
#include "ExitCommand.hpp"
#include "HistoryCommand.hpp"
#include "MessageCommand.hpp"
#include "PipeCommand.hpp"
#include "PTimeCommand.hpp"
#include "SystemCommand.hpp"

class Test {
    public:
        static void testShellConstruction();
        static void testCdCommandConstruction();
        static void testExitCommandConstuction();
        static void testHistoryCommandConstruction();
        static void testMessageCommandConstruction();
        static void testPipeCommandConstruction();
        static void testSystemCommandConstruction();
        static void testCommandFactory();
        
        static void runTests();
    
};

void Test::testShellConstruction() {
    Shell shell = Shell();
    bool passed = true;
    if((double)shell.getChildPtime().count() != 0.00){
        passed = false;
    }
    CommandFactory* fact = &shell.getCommandFactory();
    if(fact == nullptr) {
        passed = false;
    }
    if(passed) {
        std::cout << "PASSED: testShellConstruction" << std::endl;
    } else {
        std::cout << "FAILED: testShellConstruction" << std::endl;
    }
}

void Test::testCdCommandConstruction() {
    std::string str = "cd folder1/folder2";
    Shell shell = Shell();
    bool passed = true;
    
    CdCommand command = CdCommand(str,shell);
    if(command.getCmd() != str) {
        passed = false;
    }
    if((double)command.getChildPtime().count() != 0.00) {
        passed = false;
    }
    
    if(passed) {
        std::cout << "PASSED: testCdCommandConstruction" << std::endl;
    } else {
        std::cout << "FAILED: testCdCommandConstruction" << std::endl;
    }
}

void Test::testExitCommandConstuction() {
    std::string str = "exit";
    Shell shell = Shell();
    bool passed = true;
    
    ExitCommand command = ExitCommand(str,shell);
    if(command.getCmd() != str) {
        passed = false;
    }
    if((double)command.getChildPtime().count() != 0.00) {
        passed = false;
    }
    
    if(passed) {
        std::cout << "PASSED: testExitCommandConstuction" << std::endl;
    } else {
        std::cout << "FAILED: testExitCommandConstruction" << std::endl;
    }
}

void Test::testMessageCommandConstruction() {
    std::string str = "someCommandThatWarrantsAMessage";
    Shell shell = Shell();
    bool passed = true;
    
    MessageCommand command = MessageCommand(str,shell,"message for this");
    if(command.getCmd() != str) {
        passed = false;
    }
    if((double)command.getChildPtime().count() != 0.00) {
        passed = false;
    }
    if(command.getMessage() != "message for this") {
        passed = false;
    }
    
    if(passed) {
        std::cout << "PASSED: testMessageCommandConstruction" << std::endl;
    } else {
        std::cout << "FAILED: testMessageCommandConstruction" << std::endl;
    }
}

void Test::testHistoryCommandConstruction() {
    std::string str = "history";
    Shell shell = Shell();
    bool passed = true;
    
    HistoryCommand command = HistoryCommand(str,shell);
    if(command.getCmd() != str) {
        passed = false;
    }
    if((double)command.getChildPtime().count() != 0.00) {
        passed = false;
    }
    
    if(passed) {
        std::cout << "PASSED: testHistoryCommandConstruction" << std::endl;
    } else {
        std::cout << "FAILED: testHistoryCommandConstruction" << std::endl;
    }
}

void Test::testPipeCommandConstruction() {
    std::string str = "ls -l | more";
    Shell shell = Shell();
    bool passed = true;
    
    PipeCommand command = PipeCommand(str,shell);
    
    if(command.getCmd() != str) {
        passed = false;
    }
    
    if((double)command.getChildPtime().count() != 0.00) {
        passed = false;
    }
    
    if(passed) {
        std::cout << "PASSED: testPipeCommandConstruction" << std::endl;
    } else {
        std::cout << "FAILED: testPipeCommandConstruction" << std::endl;
    }
}

void Test::testSystemCommandConstruction() {
    std::string str = "ls -l";
    Shell shell = Shell();
    bool passed = true;

    SystemCommand command = SystemCommand(str,shell);
    
    if(command.getCmd() != str) {
        passed = false;
    }
    
    if((double)command.getChildPtime().count() != 0.00) {
        passed = false;
    }
    
    if(passed) {
        std::cout << "PASSED: testSystemCommandConstruction" << std::endl;
    } else {
        std::cout << "FAILED: testSystemCommandConstruction" << std::endl;
    }
}


void Test::testCommandFactory() {
    Shell shell = Shell();
    CommandFactory factory = CommandFactory();
    bool passed = true;
    
    std::string str = "ls -l";
    Command* command = factory.newCommand(str, shell);
    if(command == nullptr) {
        passed = false;
    }
    
    if(command->getCmd() != str) {
        passed = false;
    }
    
    if((double)command->getChildPtime().count() != 0.00) {
        passed = false;
    }
    
    delete command;
    command = nullptr;
    
    str = "cd folder1";
    command = factory.newCommand(str, shell);
    if(command == nullptr) {
        passed = false;
    }
    
    if(command->getCmd() != str) {
        passed = false;
    }
    
    if((double)command->getChildPtime().count() != 0.00) {
        passed = false;
    }
    delete command;
    command = nullptr;
    
    if(factory.getHistoryBuffer().size() != 2) {
        passed = false;
    }
    
    if(passed) {
        std::cout << "PASSED: testCommandFactory" << std::endl;
    } else {
        std::cout << "FAILED: testCommandFactory" << std::endl;
    }
}

void Test::runTests() {
    testCdCommandConstruction();
    testCommandFactory();
    testExitCommandConstuction();
    testHistoryCommandConstruction();
    testMessageCommandConstruction();
    testPipeCommandConstruction();
    testShellConstruction();
    testSystemCommandConstruction();
}
