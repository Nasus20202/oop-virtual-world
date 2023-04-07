#include "World.h"
#include <iostream>

World::World(int width, int height) : width(width), height(height) {
    map.resize(width * height);
}

World::~World() {

}

void World::Print(int x, int y, int range) {
    int startX = x - range;
    int startY = y - range;
    if(startX < 0)
        startX = 0;
    if(startY < 0)
        startY = 0;
    int endX = x + range;
    int endY = y + range;
    if(endX >= width)
        endX = width - 1;
    if(endY >= height)
        endY = height - 1;
    for (int itY = startY; itY <= endY; itY++) {
        for (int itX = startX; itX <= endX; itX++) {
            if (IsOccupied(itX, itY))
                std::cout << GetOrganism(itX, itY).getSymbol() << " ";
            else
                std::cout << "  ";
        }
        std::cout << std::endl;
    }
}

Tile &World::GetTile(int x, int y) {
    return map[y * width + x];
}

Organism &World::GetOrganism(int x, int y) {
    if(!IsOccupied(x, y))
        throw std::runtime_error("Tile is not occupied");
    return *GetTile(x, y).GetOrganism();
}

bool World::IsOccupied(int x, int y) {
    return GetTile(x, y).IsOccupied();
}
