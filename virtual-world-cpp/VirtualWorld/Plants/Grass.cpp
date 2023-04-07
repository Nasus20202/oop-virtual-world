#include "Grass.h"

Grass::Grass(int x, int y, void *world) : Plant(x, y, 0, 0, '_', world) {}

Plant *Grass::Clone(int x, int y, void *world) {
    return new Grass(x, y, world);
}

std::string Grass::GetName() {
    return "Grass";
}
