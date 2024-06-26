#include "Sheep.h"

Sheep::Sheep(int x, int y, World* world):
Animal(x, y, 4, 4, 0, sheepCode, world) {}

bool Sheep::AttackPaired(Organism *attacker) {
    return false;
}

bool Sheep::TryToBreed(Organism *other) {
    if(dynamic_cast<Sheep*>(other) != nullptr)
        return true;
    return false;
}

std::string Sheep::GetName() {
    return "Sheep";
}

Organism *Sheep::Clone(int x, int y, World *world) {
    return new Sheep(x, y, world);
}
