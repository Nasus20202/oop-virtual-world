#pragma once
#include "../Organism.h"
#include "../World.h"

class Plant : public Organism {
public:
    ~Plant() override;
    void Action() override;
    Plant(int x, int y, int strength, int age, char symbol, void* world);
    virtual Plant* Clone(int x, int y, void* world) = 0;
};