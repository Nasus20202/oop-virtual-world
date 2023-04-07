#include "Plant.h"

Plant::Plant(int x, int y, int strength, int age, char symbol, void* world) :
            Organism(x, y, strength, 0, age, symbol, world) {}
