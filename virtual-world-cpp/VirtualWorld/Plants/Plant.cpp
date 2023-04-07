#include "Plant.h"

Plant::Plant(int x, int y, int strength, int age, char symbol, void* world) :
            Organism(x, y, strength, 0, age, symbol, world) {}

void Plant::Action() {
    World* world = (World*)this->world;
    int x = rand() % 3 - 1;
    int y = rand() % 3 - 1;
    if (x == 0 && y == 0) return;
    if(x + this->x < 0 || x + this->x >= world->GetWidth() || y + this->y < 0 || y + this->y >= world->GetHeight())
        return;
    if (world->GetOrganism(x + this->x, y + this->y) == nullptr) {
        Plant* newPlant = this->Clone(x + this->x, y + this->y, this->world);
        world->AddOrganism(newPlant);
    }

}
