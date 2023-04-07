cmake_minimum_required(VERSION 3.24)
project(virtual_world_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(virtual_world_cpp main.cpp Game.cpp Game.h VirtualWorld/World.cpp VirtualWorld/World.h VirtualWorld/Organism.cpp VirtualWorld/Organism.h VirtualWorld/Tile.cpp VirtualWorld/Tile.h VirtualWorld/Animals/Animal.cpp VirtualWorld/Animals/Animal.h VirtualWorld/Plants/Plant.cpp VirtualWorld/Plants/Plant.h VirtualWorld/Animals/Wolf.cpp VirtualWorld/Animals/Wolf.h VirtualWorld/Animals/Sheep.cpp VirtualWorld/Animals/Sheep.h)
