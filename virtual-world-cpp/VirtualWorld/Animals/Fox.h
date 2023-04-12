#pragma once
#include "Animal.h"

class Fox : public Animal {
public:
    Fox(int x, int y, World* world);
    bool AttackPaired(Organism *attacker) override;
    bool TryToBreed(Organism *other) override;
    std::string GetName() override;
    Organism* Clone(int x, int y, World* world) override;
    void Action() override;
};
