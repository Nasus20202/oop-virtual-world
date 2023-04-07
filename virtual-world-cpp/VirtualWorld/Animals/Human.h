#pragma once
#include "Animal.h"
class Human : public Animal {
    int moveX = 0, moveY = 0;
public:
    Human(int x, int y, void* world);
    void Action() override;
    void Collision(Organism *other) override;
    bool AttackPaired(Organism *attacker) override;
    void SpecialAbility();
    void Move(int x, int y);
};
