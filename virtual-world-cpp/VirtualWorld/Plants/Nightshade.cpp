#include "Nightshade.h"

Nightshade::Nightshade(int x, int y, void *world) : Plant(x, y, 99, 0, nightshadeCode, world) {}

Plant *Nightshade::Clone(int x, int y, void *world) {
    return new Nightshade(x, y, world);
}

std::string Nightshade::GetName() {
    return "Nightshade";
}

bool Nightshade::AttackPaired(Organism *attacker) {
    attacker->Kill();
    this->Kill();
    World *w = (World *) world;
    w->GetTile(getX(), getY())->SetOrganism(nullptr);
    w->GetTile(attacker->getX(), attacker->getY())->SetOrganism(nullptr);
    w->AddMessage(attacker->GetName() + " ate nightshade and died!");
    return true;
}
