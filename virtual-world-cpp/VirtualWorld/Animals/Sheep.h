#pragma once
#include "Animal.h"

class Sheep : public Animal {
public:
    Sheep(int x, int y);
    void Action() override;
    void Collision(Organism &other) override;
    bool AttackPaired(Organism &attacker) override;
    void Breed() override;
    void Move() override;
    void Save(std::ofstream& file) override;
    void Load(std::ifstream& file) override;
};