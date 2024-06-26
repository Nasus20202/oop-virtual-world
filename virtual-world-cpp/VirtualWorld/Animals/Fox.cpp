#include <string>
#include "Fox.h"

Fox::Fox(int x, int y, World *world) : Animal(x, y, 3, 7, 0, foxCode, world) {}

bool Fox::AttackPaired(Organism *attacker) {
    return false;
}

bool Fox::TryToBreed(Organism *other) {
    if(dynamic_cast<Fox*>(other) != nullptr)
        return true;
    return false;
}

std::string Fox::GetName() {
    return "Fox";
}

Organism *Fox::Clone(int x, int y, World *world) {
    return new Fox(x, y, world);
}

void Fox::Action() {
    int x = rand() % 3 - 1;
    int y = rand() % 3 - 1;
    if (x == 0 && y == 0) return;
    if(x + this->x < 0 || x + this->x >= this->world->GetWidth() || y + this->y < 0 || y + this->y >= this->world->GetHeight())
        return;
    Organism* other = this->world->GetOrganism(x + this->x, y + this->y);
    if(other == this)
        return;
    if (other != nullptr) {
        if(other->getStrength() > this->getStrength()) {
            this->world->AddMessage("Fox's great smell saved him from " + other->GetName() + " at " + std::to_string(other->getX()) + " " + std::to_string(other->getY()) + "!");
            return;
        }
        this->Collision(other);
    } else {
        this->world->MoveOrganism(this, x + this->x, y + this->y);
    }
}
