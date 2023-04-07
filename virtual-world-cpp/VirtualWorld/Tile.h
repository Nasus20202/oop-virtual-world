#pragma once
#include "Organism.h"
class Tile {
private:
    Organism* organism = nullptr;
    bool isOccupied = false;
public:
    void SetOrganism(Organism* organism);
    Organism* GetOrganism();
    bool IsOccupied();
    void Clear();
};
