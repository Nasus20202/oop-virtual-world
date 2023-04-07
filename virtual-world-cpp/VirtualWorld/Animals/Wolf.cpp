#include "Wolf.h"

Wolf::Wolf(int x, int y, void* world):
        Animal(x, y, 9, 5, 0, 'W', world) {}

bool Wolf::AttackPaired(Organism *attacker) {
    return false;
}

bool Wolf::TryToBreed(Organism *other) {
    if(dynamic_cast<Wolf*>(other) != nullptr)
        return true;
    return false;
}

std::string Wolf::GetName() {
    return "Wolf";
}

Organism *Wolf::Clone(int x, int y, void *world) {
    return new Wolf(x, y, world);
}
