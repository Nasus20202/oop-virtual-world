#include <string>
#include "Animal.h"

Animal::Animal(int x, int y, int strength, int initiative, int age, char symbol, World* world) :
                Organism(x, y, strength, initiative, age, symbol, world) {}

void Animal::Collision(Organism *other) {
    if(this->TryToBreed(other)){
        const int minAge = 5;
        if(getAge() < minAge || other->getAge() < minAge)
            return;
        int x = 0, y = 0;
        while(x == 0 && y == 0 || (x + getX() < 0 || x + getX() >= this->world->GetWidth()
                                || y + getY() < 0 || y + getY() >= this->world->GetHeight())){
            x = rand() % 3 - 1;
            y = rand() % 3 - 1;
        }
        x += getX(); y += getY();
        Organism *organism = world->GetOrganism(x, y);
        if(dynamic_cast<Animal*>(organism) != nullptr) // check if there is animal
            return;
        if(organism != nullptr)
            world->RemoveOrganism(organism);  // remove plant under new animal
        world->AddOrganism(this->Clone(x, y, world));
        world->AddMessage("New " + this->GetName() + " was born at " + std::to_string(x) + " " + std::to_string(y));
    }
    else
        Organism::Collision(other); // attack
}

void Animal::Action() {
    int x = rand() % 3 - 1;
    int y = rand() % 3 - 1;
    if (x == 0 && y == 0) return;
    if(x + this->x < 0 || x + this->x >= world->GetWidth() || y + this->y < 0 || y + this->y >= world->GetHeight())
        return;
    Organism* other = world->GetOrganism(x + this->x, y + this->y);
    if(other == this)
        return;
    if (other != nullptr) {
        this->Collision(other);
    } else {
        world->MoveOrganism(this, x + this->x, y + this->y);
    }
}

Animal::~Animal() {

}
