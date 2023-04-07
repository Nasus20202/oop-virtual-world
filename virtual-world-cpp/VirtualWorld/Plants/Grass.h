#pragma once
#include "Plant.h"

class Grass : public Plant {
public:
    Grass(int x, int y, void* world);
    Plant* Clone(int x, int y, void* world) override;
    void Action() override;
    void Collision(Organism *other) override;
    bool AttackPaired(Organism *attacker) override;
    std::string GetName() override;
};
