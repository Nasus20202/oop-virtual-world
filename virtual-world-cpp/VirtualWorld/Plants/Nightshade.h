#pragma once
#include "Plant.h"

class Nightshade : public Plant {
public:
    Nightshade(int x, int y, World* world);
    Plant* Clone(int x, int y, World* world) override;
    std::string GetName() override;
    bool AttackPaired(Organism* attacker) override;
};