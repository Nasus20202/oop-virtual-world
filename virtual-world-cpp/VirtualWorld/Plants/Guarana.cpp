//
// Created by Nasus on 08.04.2023.
//

#include "Guarana.h"

Guarana::Guarana(int x, int y, void *world) : Plant(x, y, 0, 0, 'g', world) {}

Plant *Guarana::Clone(int x, int y, void *world) {
    return new Guarana(x, y, world);
}

std::string Guarana::GetName() {
    return "Guarana";
}

bool Guarana::AttackPaired(Organism *attacker) {
    attacker->setStrength(attacker->getStrength() + 3);
    World* w = (World*) world;
    w->AddMessage(attacker->GetName() + " ate guarana and gained 3 strength points!");
    return false;
}
