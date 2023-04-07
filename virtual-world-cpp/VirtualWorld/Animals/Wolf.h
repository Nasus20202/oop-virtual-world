#pragma once
#include "Animal.h"

class Wolf : public Animal {
public:
    Wolf(int x, int y, void* world);
    bool AttackPaired(Organism &attacker) override;
    void Save(std::ofstream& file) override;
    void Load(std::ifstream& file) override;
};