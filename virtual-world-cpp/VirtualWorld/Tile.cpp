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

Tile::~Tile() {
    delete organism;
}

void Tile::killOrganism() {
    delete organism;
    organism = nullptr;
}
