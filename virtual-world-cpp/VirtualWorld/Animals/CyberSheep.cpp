#include "CyberSheep.h"
#include "../Plants/SosnowskysHogweed.h"

CyberSheep::CyberSheep(int x, int y, void* world) : Animal(x, y, 11, 4, 0, cyberSheepCode, world) {}

bool CyberSheep::TryToBreed(Organism *other) {
    if(dynamic_cast<CyberSheep*>(other) != nullptr)
        return true;
    return false;
}

void CyberSheep::Action() {
    World* w = (World*)this->world;
    bool found = false; int foundX = -1, foundY = -1, distance = INT32_MAX;
    for(auto organism : w->GetOrganisms()){
        if(dynamic_cast<SosnowskysHogweed*>(organism) != nullptr){
            int x = organism->getX(), y = organism->getY();
            found = true;
            int newDistance = abs(this->x - x) + abs(this->y - y);
            if(newDistance < distance){
                distance = newDistance;
                foundX = x;
                foundY = y;
            }
        }
    }
    if(found){
        int dx = 0, dy = 0;
        if(foundX > this->x)
            dx = 1;
        else if(foundX < this->x)
            dx = -1;
        if(foundY > this->y)
            dy = 1;
        else if(foundY < this->y)
            dy = -1;
        Organism *other = w->GetOrganism(this->x + dx, this->y + dy);
        if(other == this)
            return;
        if(other == nullptr)
            w->MoveOrganism(this, this->x + dx, this->y + dy);
        else
            this->Collision(other);

    } else
        Animal::Action();
}

void CyberSheep::Collision(Organism *attacker) {
    if(dynamic_cast<SosnowskysHogweed*>(attacker) == nullptr)
        Animal::Collision(attacker);
    else {
        attacker->Kill();
        World *w = (World *) this->world;
        w->AddMessage("CyberSheep destroyed " + attacker->GetName() + " at " + std::to_string(attacker->getX()) + " " +
                      std::to_string(attacker->getY()) + "!");
        w->GetTile(attacker->getX(), attacker->getY())->SetOrganism(nullptr);
        w->MoveOrganism(this, attacker->getX(), attacker->getY());
    }
}

std::string CyberSheep::GetName() {
    return "CyberSheep";
}

Organism *CyberSheep::Clone(int x, int y, void *world) {
    return new CyberSheep(x, y, world);
}

bool CyberSheep::AttackPaired(Organism *attacker) {
    if(dynamic_cast<SosnowskysHogweed*>(attacker) != nullptr)
        return true;
    return false;
}
