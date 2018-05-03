project(paraviac++ CXX)
cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_FLAGS "-std=c++1z")

#declares an executable program
add_executable(paraviac++
	main.cpp
	#upkeep.cpp


)

find_package(Curses)
#Declare a library name 'curses'.
#add_library(players
#	upkeep.cpp
#	player.cpp
#	actions.cpp
#	)

target_link_libraries(paraviac++ ${CURSES_LIBRARIES})
