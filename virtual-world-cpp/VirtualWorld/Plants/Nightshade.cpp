#include "Nightshade.h"

Nightshade::Nightshade(int x, int y, World *world) : Plant(x, y, 99, 0, nightshadeCode, world) {}

Plant *Nightshade::Clone(int x, int y, World *world) {
    return new Nightshade(x, y, world);
}

std::string Nightshade::GetName() {
    return "Nightshade";
}

bool Nightshade::AttackPaired(Organism *attacker) {
    attacker->Kill();
    this->Kill();
    this->world->GetTile(getX(), getY())->SetOrganism(nullptr);
    this->world->GetTile(attacker->getX(), attacker->getY())->SetOrganism(nullptr);
    this->world->AddMessage(attacker->GetName() + " ate nightshade and died!");
    return true;
}
