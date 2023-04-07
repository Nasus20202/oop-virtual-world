cmake_minimum_required(VERSION 3.24)
project(virtual_world_cpp)

set(CMAKE_CXX_STANDARD 17)

add_executable(virtual_world_cpp main.cpp Game.cpp Game.h VirtualWorld/World.cpp VirtualWorld/World.h VirtualWorld/Organism.cpp VirtualWorld/Organism.h VirtualWorld/Tile.cpp VirtualWorld/Tile.h VirtualWorld/Animals/Animal.cpp VirtualWorld/Animals/Animal.h VirtualWorld/Plants/Plant.cpp VirtualWorld/Plants/Plant.h VirtualWorld/Animals/Wolf.cpp VirtualWorld/Animals/Wolf.h VirtualWorld/Animals/Sheep.cpp VirtualWorld/Animals/Sheep.h VirtualWorld/Animals/Human.cpp VirtualWorld/Animals/Human.h VirtualWorld/AllOgranisms.h VirtualWorld/Plants/Grass.cpp VirtualWorld/Plants/Grass.h VirtualWorld/Animals/Fox.cpp VirtualWorld/Animals/Fox.h VirtualWorld/Animals/Turtle.cpp VirtualWorld/Animals/Turtle.h VirtualWorld/Animals/Antelope.cpp VirtualWorld/Animals/Antelope.h VirtualWorld/Plants/Dandelion.cpp VirtualWorld/Plants/Dandelion.h VirtualWorld/Plants/Guarana.cpp VirtualWorld/Plants/Guarana.h VirtualWorld/Plants/Nightshade.cpp VirtualWorld/Plants/Nightshade.h VirtualWorld/Plants/SosnowskysHogweed.cpp VirtualWorld/Plants/SosnowskysHogweed.h)
