#include <string>
#include "Turtle.h"

Turtle::Turtle(int x, int y, World *world) : Animal(x, y, 2, 1, 0, turtleCode, world) {}

bool Turtle::AttackPaired(Organism *attacker) {
    if(attacker->getStrength() >= 5)
        return false;
    this->world->AddMessage("Turtle blocked attack from " + attacker->GetName() + " at " + std::to_string(attacker->getX()) + " " + std::to_string(attacker->getY()) + "!");
    return true;
}

bool Turtle::TryToBreed(Organism *other) {
    if(dynamic_cast<Turtle*>(other) != nullptr)
        return true;
    return false;
}

std::string Turtle::GetName() {
    return "Turtle";
}

Organism *Turtle::Clone(int x, int y, World *world) {
    return new Turtle(x, y, world);
}

void Turtle::Action() {
    int random = rand() % 4;
    if(random == 0)
        Animal::Action();
}
