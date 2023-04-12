#pragma once
#include "Plant.h"

class Grass : public Plant {
public:
    Grass(int x, int y, World* world);
    Plant* Clone(int x, int y, World* world) override;
    std::string GetName() override;
};
