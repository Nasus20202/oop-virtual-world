#pragma once
#include "Organism.h"
class Tile {
private:
    bool isOccupied = false;
    Organism* organism = nullptr;
public:
    void SetOrganism(Organism* organism);
    Organism* GetOrganism();
    bool IsOccupied();
    void Clear();
};