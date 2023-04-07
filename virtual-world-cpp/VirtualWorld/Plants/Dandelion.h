#pragma once
#include "Plant.h"
class Dandelion : public Plant {
public:
    Dandelion(int x, int y, void* world);
    Plant* Clone(int x, int y, void* world) override;
    std::string GetName() override;
    void Action() override;
};

