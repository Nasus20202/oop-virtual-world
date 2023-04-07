#pragma once
#include <vector>
#include "Tile.h"

class World {
private:
    int width, height;
    std::vector<Tile> map;
public:
    World(int width, int height);
    ~World();
    void Print(int x, int y, int range);
    Tile& GetTile(int x, int y);
    Organism& GetOrganism(int x, int y);
    bool IsOccupied(int x, int y);
};
