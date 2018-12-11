This is an implementation of a command shell in C++. 

Originally this was all built in one file with no thought given to the design,
extensibility, or maintainability. 

The program was redesigned into these main parts:
    Shell
        -This is the main object which once run() is called will loop until the 
         user inputs the 'exit' command. The Shell utilizes the CommandFactory
         class (which is an implementation of the Factory design pattern) to 
         create a Command object based on the user's input, after which the Command
         object's execute() method is called. 
    
    CommandFactory
        -This object is responsible for creating and returning the correct Command 
        subclass based on a command string (usually entered by the user). It also
        keeps a running list of command strings passed into the factory in the 
        historyBuffer variable. 
        
    Command(s)
        -There are many types of commands. SystemCommand(s) are commands that are
        not built into the shell and must be executed by calling execvp to make 
        a system call. PipeCommands are similar, but with multiple system command 
        strings piped together. Other command types are built-in commands which 
        are executed by the shell without making a system call via execvp. 
         The Command class uses the strategy design pattern. Each Command subclass
        must implement an execute() method which handles the implementation of what 
        happens and how arguments are handled for that command.
        
This implementation allows for much easier and straightforward extension and 
maintainability. To extend this program to support new commands, simply create 
a new class which inherits from Command, implement the execute() method, and add 
the logic for determining and creating an instance of the class in the 
CommandFactory. 

All this was done in an effort to make the code more modular, extensible, and 
maintainable. 

