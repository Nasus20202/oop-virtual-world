#include <string>
#include "Antelope.h"

Antelope::Antelope(int x, int y, World *world) : Animal(x, y, 4, 4, 0, antelopeCode, world) {}

bool Antelope::AttackPaired(Organism *attacker) {
    int random = rand() % 2;
    if(random == 0)
        return false;
    for(int x = -1; x <= 1; x++)
        for(int y = -1; y <= 1; y++) {
            if(x == 0 && y == 0 || this->getX() + x < 0 || this->getX() + x >= this->world->GetWidth() ||
                            this->getY() + y < 0 || this->getY() + y >= this->world->GetHeight())
                continue;
            if (this->world->GetTile(this->getX() + x, this->getY() + y)->GetOrganism() == nullptr) {
                this->world->MoveOrganism(this, this->getX() + x, this->getY() + y);
                this->world->AddMessage("Antelope run away from " + attacker->GetName() + " at " + std::to_string(attacker->getX()) + " " + std::to_string(attacker->getY()) + "!");
                return true;
            }
        }
    return false;
}

bool Antelope::TryToBreed(Organism *other) {
    if(dynamic_cast<Antelope*>(other) != nullptr)
        return true;
    return false;
}

std::string Antelope::GetName() {
    return "Antelope";
}

Organism *Antelope::Clone(int x, int y, World *world) {
    return new Antelope(x, y, world);
}

void Antelope::Action() {
    for(int i = 0; i < 2; i++)
        if(IsAlive())
            Animal::Action();
}
