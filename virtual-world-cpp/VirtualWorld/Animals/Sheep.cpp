#include "Sheep.h"

Sheep::Sheep(int x, int y, void* world):
Animal(x, y, 4, 4, 0, 'S', world) {}

bool Sheep::AttackPaired(Organism *attacker) {
    return false;
}