project(war CXX)

set(CMAKE_CXX_FLAGS "-std=c++1z")

add_library(cards
	card.cpp
	deck.cpp)

add_executable(war
	player.cpp
	game.cpp
	main.cpp)

Target_link_libraries(war cards)