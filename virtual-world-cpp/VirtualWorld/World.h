#pragma once
#include <vector>
#include "Tile.h"

class World {
private:
    int width, height;
    std::vector<Tile> map;
    Tile& GetTile(int x, int y);
public:
    World(int width, int height);
    ~World();
    void Print();
};
