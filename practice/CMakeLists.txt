project(war CXX)

set(CMAKE_CXX_FLAGS "-std=c++1z")


add_executable(war 
  main.cpp
  card.cpp
)