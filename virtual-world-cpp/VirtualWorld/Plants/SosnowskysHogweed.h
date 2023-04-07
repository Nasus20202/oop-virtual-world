#pragma once
#include "Plant.h"

class SosnowskysHogweed : public Plant {
public:
    SosnowskysHogweed(int x, int y, void* world);
    Plant* Clone(int x, int y, void* world) override;
    std::string GetName() override;
    void Action() override;
    bool AttackPaired(Organism* attacker) override;
};
