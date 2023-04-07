#include "Human.h"

Human::Human(int x, int y, void* world) : Animal(x, y, 5, 4, 0, humanCode, world) {
}
void Human::Action() {
    World* world = (World*)this->world;
    int newX = this->x + moveX, newY = this->y + moveY;
    if (newX < 0 || newX >= world->GetWidth() || newY < 0 || newY >= world->GetHeight())
        return;
    if (world->GetOrganism(newX, newY) == nullptr)
        world->MoveOrganism(this, newX, newY);
    else
        this->Collision(world->GetOrganism(newX, newY));
}

void Human::Collision(Organism* other) {
    Animal::Collision(other);
}

bool Human::AttackPaired(Organism *attacker) {
    return false;
}

void Human::SpecialAbility() {

}

void Human::Move(int x, int y) {
    moveX = x, moveY = y;
}

bool Human::TryToBreed(Organism *other) {
    return false;
}

std::string Human::GetName() {
    return "Human";
}

Organism *Human::Clone(int x, int y, void *world) {
    return nullptr;
}
