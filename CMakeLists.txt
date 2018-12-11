cmake_minimum_required (VERSION 2.0)
project (cppShellHW5)

if (CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11 -pthread -O3 ${CMAKE_CXX_FLAGS}")
endif()

add_executable(cppShellHW5
	main.cpp
	Shell.hpp
	Shell.cpp
	Command.hpp
	Command.cpp
	CdCommand.hpp
	CdCommand.cpp
	ExitCommand.hpp
	ExitCommand.cpp
	HistoryCommand.hpp
	HistoryCommand.cpp
	MessageCommand.hpp
	MessageCommand.cpp
	PipeCommand.hpp
	PipeCommand.cpp
	PTimeCommand.hpp
	PTimeCommand.cpp
	SystemCommand.hpp
	SystemCommand.cpp
	CommandFactory.hpp
	CommandFactory.cpp
	Test.hpp
	Test.cpp
)
