#pragma once
#include "../Organism.h"
#include "../World.h"

class Animal : public Organism {
public:
    ~Animal() override;
    void Action() override;
    void Collision(Organism *other) override;
    Animal(int x, int y, int strength, int initiative, int age, char symbol, void* world);
};
