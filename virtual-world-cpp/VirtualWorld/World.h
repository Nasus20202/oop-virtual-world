#pragma once
#include <vector>
#include "Organism.h"
#include "Tile.h"

class World {
private:
    int width, height;
    std::vector<Tile> map;
    std::vector<Organism*> organisms;
    Tile& GetTile(int x, int y);
public:
    World(int width, int height);
    ~World();
    void Print();
};
