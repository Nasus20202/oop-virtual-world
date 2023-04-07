#include "Tile.h"

bool Tile::IsOccupied() {
    return isOccupied;
}

Organism *Tile::GetOrganism() {
    return organism;
}

void Tile::SetOrganism(Organism *newOrganism) {
    isOccupied = newOrganism != nullptr;
    this->organism = newOrganism;
}
