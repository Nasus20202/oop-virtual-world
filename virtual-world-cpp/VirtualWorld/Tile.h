#pragma once
#include "Organism.h"
class Tile {
private:
    Organism* organism = nullptr;
public:
    ~Tile();
    void SetOrganism(Organism* organism);
    Organism* GetOrganism();
    bool IsOccupied();
    void killOrganism();
};