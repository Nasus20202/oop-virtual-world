#include "Tile.h"

bool Tile::IsOccupied() {
    if(organism == nullptr)
        return false;
    return organism != nullptr;
}

Organism *Tile::GetOrganism() {
    return organism;
}

void Tile::SetOrganism(Organism *newOrganism) {
    this->organism = newOrganism;
}
