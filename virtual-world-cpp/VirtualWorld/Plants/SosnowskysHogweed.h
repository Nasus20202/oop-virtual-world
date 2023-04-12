#pragma once
#include "Plant.h"

class SosnowskysHogweed : public Plant {
public:
    SosnowskysHogweed(int x, int y, World* world);
    Plant* Clone(int x, int y, World* world) override;
    std::string GetName() override;
    void Action() override;
    bool AttackPaired(Organism* attacker) override;
};
