#pragma once
#include "../Organism.h"
#include "../World.h"

class Animal : public Organism {
protected:
    virtual void Move() = 0;
    virtual void Breed() = 0;
public:
    Animal(int x, int y, int strength, int initiative, int age, char symbol, void* world);
};
