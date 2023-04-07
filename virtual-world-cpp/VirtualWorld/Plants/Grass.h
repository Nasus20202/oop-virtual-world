#pragma once
#include "Plant.h"

class Grass : public Plant {
public:
    Grass(int x, int y, void* world);
    Plant* Clone(int x, int y, void* world) override;
    std::string GetName() override;
};
