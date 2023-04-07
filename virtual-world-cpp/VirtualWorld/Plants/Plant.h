#pragma once
#include "../Organism.h"
#include "../World.h"

class Plant : public Organism {
protected:
    virtual void Breed() = 0;
public:
    Plant(int x, int y, int strength, int age, char symbol, void* world);
};