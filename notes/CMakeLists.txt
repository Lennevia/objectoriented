project(shuffle CXX)

set(CMAKE_CXX_FLAGS "-std=c++1z")

# if you have external libraries with an external dependency
# this will find a config file for curses
find_package(curses)

# declare a library named 'cards'
add_library(cards
	bitcard.cpp)

# declares desire of wanting to compile a program'shiffle'
add_executable(shuffle
	shuffle.cpp)
# Just an example of setting a var
set(libs ${CURSES_LIBRARIES})

# Specifies that shuffle should ink against the library cards. 
# This basically tells CMake to compile the executable like this:
#
# $CXX <inputs> -lcards
#
Target_link_libraries(shuffle cards)