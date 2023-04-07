#include <string>
#include "Antelope.h"

Antelope::Antelope(int x, int y, void *world) : Animal(x, y, 4, 4, 0, antelopeCode, world) {}

bool Antelope::AttackPaired(Organism *attacker) {
    int random = rand() % 2;
    if(random == 0)
        return false;
    World* w = (World*)this->world;
    for(int x = -1; x <= 1; x++)
        for(int y = -1; y <= 1; y++) {
            if(x == 0 && y == 0 || this->getX() + x < 0 || this->getX() + x >= w->GetWidth() || this->getY() + y < 0 || this->getY() + y >= w->GetHeight())
                continue;
            if (w->GetTile(this->getX() + x, this->getY() + y)->GetOrganism() == nullptr) {
                w->MoveOrganism(this, this->getX() + x, this->getY() + y);
                w->AddMessage("Antelope run away from " + attacker->GetName() + " at " + std::to_string(attacker->getX()) + " " + std::to_string(attacker->getY()) + "!");
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

Organism *Antelope::Clone(int x, int y, void *world) {
    return new Antelope(x, y, world);
}

void Antelope::Action() {
    World* world = (World*)this->world;
    int x = rand() % 5 - 2;
    int y = rand() % 5 - 2;
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
