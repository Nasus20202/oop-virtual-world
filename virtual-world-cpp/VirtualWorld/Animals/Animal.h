#pragma once
#include "../Organism.h"
#include "../World.h"

class Animal : public Organism {
private:
    void Action() override;
    void Collision(Organism &other) override;
public:
    Animal(int x, int y, int strength, int initiative, int age, char symbol, void* world);
};
