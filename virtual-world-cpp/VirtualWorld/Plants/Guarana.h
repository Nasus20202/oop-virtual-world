#pragma once
#include "Plant.h"

class Guarana : public Plant {
public:
    Guarana(int x, int y, void* world);
    Plant* Clone(int x, int y, void* world) override;
    std::string GetName() override;
    bool AttackPaired(Organism* attacker) override;
};
