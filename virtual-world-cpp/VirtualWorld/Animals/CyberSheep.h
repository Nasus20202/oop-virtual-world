#pragma once
#include "Animal.h"

class CyberSheep : public Animal {
public:
    CyberSheep(int x, int y, void* world);
    bool TryToBreed(Organism *other) override;
    bool AttackPaired(Organism *attacker) override;
    void Action() override;
    void Collision(Organism* attacker) override;
    Organism* Clone(int x, int y, void* world) override;
    std::string GetName() override;
};

