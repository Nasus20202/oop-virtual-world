#include "Human.h"

Human::Human(int x, int y, void* world) : Animal(x, y, 5, 4, 0, 'X', world) {
}

void Human::Action() {

}

void Human::Collision(Organism &other) {

}

bool Human::AttackPaired(Organism &attacker) {
    return false;
}

void Human::Save(std::ofstream &file) {

}

void Human::Load(std::ifstream &file) {

}

void Human::SpecialAbility() {

}

void Human::Move(int x, int y) {
    World* world = (World*)this->world;
    if (x < 0 || x >= world->GetWidth() || y < 0 || y >= world->GetHeight())
        throw std::invalid_argument("Invalid coordinates");
    if (world->GetOrganism(x, y) == nullptr)
        world->MoveOrganism(this, x, y);
    else
        this->Collision(*(world->GetOrganism(x, y)));
}
