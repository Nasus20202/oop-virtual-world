#pragma once
#include "Animal.h"
class Human : public Animal {
public:
    Human(int x, int y, void* world);
    void Action() override;
    void Collision(Organism &other) override;
    bool AttackPaired(Organism &attacker) override;
    void Save(std::ofstream& file) override;
    void Load(std::ifstream& file) override;
    void SpecialAbility();
    void Move(int x, int y);
};
