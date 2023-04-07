#include "Grass.h"

Grass::Grass(int x, int y, void *world) : Plant(x, y, 0, 0, '_', world) {
}

Plant *Grass::Clone(int x, int y, void *world) {
    return new Grass(x, y, world);
}

void Grass::Action() {
    Plant::Action();
}

void Grass::Collision(Organism *other) {

}

bool Grass::AttackPaired(Organism *attacker) {
    return false;
}

std::string Grass::GetName() {
    return "Grass";
}
