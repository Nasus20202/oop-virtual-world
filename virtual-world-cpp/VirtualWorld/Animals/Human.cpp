#include "Human.h"

Human::Human(int x, int y, void* world) : Animal(x, y, 5, 4, 0, 'X', world) {
}

void Human::Action() {
    World* world = (World*)this->world;
    int newX = this->x + moveX, newY = this->y + moveY;
    if (newX < 0 || newX >= world->GetWidth() || newY < 0 || newY >= world->GetHeight())
        throw std::invalid_argument("Invalid coordinates");
    if (world->GetOrganism(newX, newY) == nullptr)
        world->MoveOrganism(this, newX, newY);
    else
        this->Collision(*(world->GetOrganism(newX, newY)));
}

void Human::Collision(Organism &other) {

}

bool Human::AttackPaired(Organism &attacker) {
    return false;
}

void Human::SpecialAbility() {

}

void Human::Move(int x, int y) {
    moveX = x, moveY = y;
}
