#pragma once
#include "Plant.h"

class Guarana : public Plant {
public:
    Guarana(int x, int y, World* world);
    Plant* Clone(int x, int y, World* world) override;
    std::string GetName() override;
    bool AttackPaired(Organism* attacker) override;
};
