project(santaparavia CXX)
cmake_minimum_required(VERSION 2.6)

##sets a variable, example
#set(libs ${CURSES_LIBRARIES})

#external library dependencies
#find_package(Curses)


#declares an executable program
add_executable(santaparavia

	main.cpp

)

#Declare a library name 'curses'.
add_library(players
	upkeep.cpp
	)

#Specifies that shuffle should link against the library cards
#This basically tells CMake to compile the executable like this:
#
# $CXX <inputs> -lcards
target_link_libraries(santaparavia ${CURSES_LIBRARIES})