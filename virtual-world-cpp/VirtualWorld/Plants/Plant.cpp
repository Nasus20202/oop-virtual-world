#include <string>
#include "Plant.h"

Plant::Plant(int x, int y, int strength, int age, char symbol, World* world) :
            Organism(x, y, strength, 0, age, symbol, world) {}

void Plant::Action() {
    int x = -1, y = -1;
    do {
        x = rand() % 3 - 1 + this->x;
        y = rand() % 3 - 1 + this->y;
    } while (x < 0 || x >= this->world->GetWidth() || y < 0 || y >= this->world->GetHeight() || (x == this->x && y == this->y));
    if(this->world->GetOrganism(x, y) != nullptr)
        return;
    int probability = rand() % seedingProbability;
    if(probability == 0){
        this->world->AddOrganism(this->Clone(x, y, world));
        this->world->AddMessage("New " + this->GetName() + " was seeded at " + std::to_string(x) + " " + std::to_string(y));
    }
}

Plant::~Plant() {

}

bool Plant::AttackPaired(Organism *attacker) {
    return false;
}
