#ifndef _SHELL_TEST_CPP_
#define _SHELL_TEST_CPP_

class Test {
    public:
        static void testShellConstruction();
        static void testCdCommandConstruction();
        static void testExitCommandConstuction();
        static void testHistoryCommandConstruction();
        static void testMessageCommandConstruction();
        static void testPipeCommandConstruction();
        static void testPTimeCommandConstruction();
        static void testSystemCommandConstruction();
        static void testCommandFactory();
        
        static void runTests();
    
};
#endif