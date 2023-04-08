#include "SosnowskysHogweed.h"
#include "../Animals/CyberSheep.h"

SosnowskysHogweed::SosnowskysHogweed(int x, int y, void *world)  : Plant(x, y, 10, 0, sosnowskyHogweedCode, world){}

Plant *SosnowskysHogweed::Clone(int x, int y, void *world) {
    return new SosnowskysHogweed(x, y, world);
}

std::string SosnowskysHogweed::GetName() {
    return "Sosnowsky's Hogweed";
}

void SosnowskysHogweed::Action() {
    Plant::Action();
    World *w = (World *) world;
    for(int x = -1; x <= 1; x++){
        for(int y = -1; y <= 1; y++){
            if(x == 0 && y == 0)
                continue;
            if(this->x + x < 0 || this->x + x >= w->GetWidth() || this->y + y < 0 || this->y + y >= w->GetHeight() || w->GetTile(this->x + x, this->y + y)->GetOrganism() == nullptr)
                continue;
            if(w->GetTile(this->x + x, this->y + y)->GetOrganism() != nullptr){
                Organism *o = w->GetTile(this->x + x, this->y + y)->GetOrganism();
                if(o == nullptr)
                    continue;
                if(dynamic_cast<SosnowskysHogweed*>(o) == nullptr && dynamic_cast<CyberSheep*>(o) == nullptr){
                    o->Kill();
                    w->GetTile(o->getX(), o->getY())->SetOrganism(nullptr);
                    w->AddMessage(o->GetName() + " was killed by toxic pine borscht!");
                }
            }
        }
    }
}

bool SosnowskysHogweed::AttackPaired(Organism *attacker) {
    attacker->Kill();
    World *w = (World *) world;
    w->GetTile(attacker->getX(), attacker->getY())->SetOrganism(nullptr);
    w->AddMessage(attacker->GetName() + " ate pine borscht and died!");
    return Plant::AttackPaired(attacker);
}
