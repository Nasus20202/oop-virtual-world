#pragma once
#include "Animal.h"

class Fox : public Animal {
public:
    Fox(int x, int y, void* world);
    bool AttackPaired(Organism *attacker) override;
    bool TryToBreed(Organism *other) override;
    std::string GetName() override;
    Organism* Clone(int x, int y, void* world) override;
    void Action() override;
};
