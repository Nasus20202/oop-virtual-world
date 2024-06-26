#pragma once
#include "../Organism.h"
#include "../World.h"

class Plant : public Organism {
    static const int seedingProbability = 4;
public:
    ~Plant() override;
    void Action() override;
    bool AttackPaired(Organism *attacker) override;
    Plant(int x, int y, int strength, int age, char symbol, World* world);
};