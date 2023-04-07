#include "Wolf.h"

Wolf::Wolf(int x, int y, void* world):
        Animal(x, y, 9, 5, 0, 'W', world) {}

bool Wolf::AttackPaired(Organism *attacker) {
    return false;
}
