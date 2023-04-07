#include "World.h"

World::World(int width, int height) {

}

World::~World() {

}

void World::Print() {

}

Tile &World::GetTile(int x, int y) {
    return map[x + y * width];
}

Organism &World::GetOrganism(int x, int y) {
    return *GetTile(x, y).GetOrganism();
}

bool World::IsOccupied(int x, int y) {
    return GetTile(x, y).IsOccupied();
}
