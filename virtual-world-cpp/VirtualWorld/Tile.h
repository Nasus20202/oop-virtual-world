#pragma once
#include "Organism.h"

class Organism;

class Tile {
private:
    Organism* organism = nullptr;
public:
    void SetOrganism(Organism* organism);
    Organism* GetOrganism();
    bool IsOccupied();
};