#pragma once
#include "Animal.h"

class Wolf : public Animal {
public:
    Wolf(int x, int y, void* world);
    bool AttackPaired(Organism &attacker) override;
};