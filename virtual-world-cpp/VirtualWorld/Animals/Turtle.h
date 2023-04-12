#pragma once
#include "Animal.h"

class Turtle : public Animal {
public:
    Turtle(int x, int y, World* world);
    bool AttackPaired(Organism *attacker) override;
    bool TryToBreed(Organism *other) override;
    std::string GetName() override;
    Organism* Clone(int x, int y, World* world) override;
    void Action() override;
};
