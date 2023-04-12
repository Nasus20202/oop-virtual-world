#include "SosnowskysHogweed.h"
#include "../Animals/CyberSheep.h"

SosnowskysHogweed::SosnowskysHogweed(int x, int y, World *world)  : Plant(x, y, 10, 0, sosnowskyHogweedCode, world){}

Plant *SosnowskysHogweed::Clone(int x, int y, World *world) {
    return new SosnowskysHogweed(x, y, world);
}

std::string SosnowskysHogweed::GetName() {
    return "Sosnowsky's Hogweed";
}

void SosnowskysHogweed::Action() {
    Plant::Action();
    for(int x = -1; x <= 1; x++){
        for(int y = -1; y <= 1; y++){
            if(x == 0 && y == 0)
                continue;
            if(this->x + x < 0 || this->x + x >= this->world->GetWidth() || this->y + y < 0 ||
                        this->y + y >= this->world->GetHeight() || this->world->GetTile(this->x + x, this->y + y)->GetOrganism() == nullptr)
                continue;
            if(this->world->GetTile(this->x + x, this->y + y)->GetOrganism() != nullptr){
                Organism *o = this->world->GetTile(this->x + x, this->y + y)->GetOrganism();
                if(o == nullptr)
                    continue;
                if(dynamic_cast<SosnowskysHogweed*>(o) == nullptr && dynamic_cast<CyberSheep*>(o) == nullptr){
                    o->Kill();
                    this->world->GetTile(o->getX(), o->getY())->SetOrganism(nullptr);
                    this->world->AddMessage(o->GetName() + " was killed by toxic pine borscht!");
                }
            }
        }
    }
}

bool SosnowskysHogweed::AttackPaired(Organism *attacker) {
    attacker->Kill();
    this->world->GetTile(attacker->getX(), attacker->getY())->SetOrganism(nullptr);
    this->world->AddMessage(attacker->GetName() + " ate pine borscht and died!");
    return Plant::AttackPaired(attacker);
}
