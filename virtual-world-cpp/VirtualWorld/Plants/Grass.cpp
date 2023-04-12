#include "Grass.h"

Grass::Grass(int x, int y, World *world) : Plant(x, y, 0, 0, grassCode, world) {}

Plant *Grass::Clone(int x, int y, World *world) {
    return new Grass(x, y, world);
}

std::string Grass::GetName() {
    return "Grass";
}
