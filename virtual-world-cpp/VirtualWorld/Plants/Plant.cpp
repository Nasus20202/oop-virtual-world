#include <string>
#include "Plant.h"

Plant::Plant(int x, int y, int strength, int age, char symbol, void* world) :
            Organism(x, y, strength, 0, age, symbol, world) {}

void Plant::Action() {
    World* w = (World*)this->world;
    int x = -1, y = -1;
    do {
        x = rand() % 3 - 1 + this->x;
        y = rand() % 3 - 1 + this->y;
    } while (x < 0 || x >= w->GetWidth() || y < 0 || y >= w->GetHeight() || (x == this->x && y == this->y));
    if(w->GetOrganism(x, y) != nullptr)
        return;
    int probability = rand() % seedingProbability;
    if(probability == 0){
        w->AddOrganism(this->Clone(x, y, world));
        w->AddMessage("New " + this->GetName() + " was seeded at " + std::to_string(x) + " " + std::to_string(y));
    }
}

Plant::~Plant() {

}

bool Plant::AttackPaired(Organism *attacker) {
    return false;
}
