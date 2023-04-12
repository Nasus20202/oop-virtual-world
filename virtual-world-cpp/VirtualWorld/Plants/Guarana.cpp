#include "Guarana.h"

Guarana::Guarana(int x, int y, World *world) : Plant(x, y, 0, 0, guaranaCode, world) {}

Plant *Guarana::Clone(int x, int y, World *world) {
    return new Guarana(x, y, world);
}

std::string Guarana::GetName() {
    return "Guarana";
}

bool Guarana::AttackPaired(Organism *attacker) {
    attacker->setStrength(attacker->getStrength() + 3);
    this->world->AddMessage(attacker->GetName() + " ate guarana and gained 3 strength points!");
    return false;
}
