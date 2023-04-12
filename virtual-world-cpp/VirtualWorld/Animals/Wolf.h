#pragma once
#include "Animal.h"

class Wolf : public Animal {
public:
    Wolf(int x, int y, World* world);
    bool AttackPaired(Organism *attacker) override;
    bool TryToBreed(Organism *other) override;
    std::string GetName() override;
    Organism* Clone(int x, int y, World* world) override;
};