#pragma once
#include "Animal.h"
class Antelope : public Animal{
public:
    Antelope(int x, int y, void* world);
    bool AttackPaired(Organism *attacker) override;
    bool TryToBreed(Organism *other) override;
    std::string GetName() override;
    Organism* Clone(int x, int y, void* world) override;
    void Action() override;
};

