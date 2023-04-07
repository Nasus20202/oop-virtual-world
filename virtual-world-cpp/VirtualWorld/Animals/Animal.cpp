#include "Animal.h"

Animal::Animal(int x, int y, int strength, int initiative, int age, char symbol, void* world) :
                Organism(x, y, strength, initiative, age, symbol, world) {}

void Animal::Collision(Organism &other) {

}

void Animal::Action() {
    World* world = (World*)this->world;
    int x = rand() % 3 - 1;
    int y = rand() % 3 - 1;
    if (x == 0 && y == 0) return;
    Organism* other = world->GetOrganism(x + this->x, y + this->y);
    if (other != nullptr) {
        this->Collision(*other);
    } else {
        world->MoveOrganism(this, x + this->x, y + this->y);
    }
}
