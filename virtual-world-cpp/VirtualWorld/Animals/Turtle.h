#pragma once
#include "Animal.h"

class Turtle : public Animal {
public:
    Turtle(int x, int y, void* world);
    bool AttackPaired(Organism *attacker) override;
    bool TryToBreed(Organism *other) override;
    std::string GetName() override;
    Organism* Clone(int x, int y, void* world) override;
    void Action() override;
};
