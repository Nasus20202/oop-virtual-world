#include "Dandelion.h"

Dandelion::Dandelion(int x, int y, void *world) : Plant(x, y, 0, 0, '*', world) {}

Plant *Dandelion::Clone(int x, int y, void *world) {
    return new Dandelion(x, y, world);
}

std::string Dandelion::GetName() {
    return "Dandelion";
}

void Dandelion::Action() {
    for(int i = 0; i < 3; i++)
        Plant::Action();
}
