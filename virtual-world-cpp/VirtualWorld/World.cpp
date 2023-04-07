#include "World.h"
#include <iostream>
#include <algorithm>
#include "AllOgranisms.h"

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
    if(startX == 0)
        endX = range * 2;
    if(startY == 0)
        endY = range * 2;
    if(endX >= width)
        startX = width - range * 2 - 1;
    if(endY >= height)
        startY = height - range * 2 - 1;
    if(endX >= width)
        endX = width - 1;
    if(endY >= height)
        endY = height - 1;
    if(startX < 0)
        startX = 0;
    if(startY < 0)
        startY = 0;
    std::cout << "\xDB";
    for(int i = startX; i <= endX; i++)
        std::cout << "\xDF\xDF";
    std::cout << "\xDB\n";
    for (int itY = startY; itY <= endY; itY++) {
        std::cout << "\xDB";
        for (int itX = startX; itX <= endX; itX++) {
            if (IsOccupied(itX, itY))
                std::cout << GetOrganism(itX, itY)->getSymbol() << " ";
            else
                std::cout << "  ";
        }
        std::cout << "\xDB\n";
    }
    std::cout << "\xDB";
    for(int i = startX; i <= endX; i++)
        std::cout << "\xDC\xDC";
    std::cout << "\xDB";
}

Tile &World::GetTile(int x, int y) {
    if(x < 0 || x >= width || y < 0 || y >= height)
        throw std::runtime_error("Tile out of bounds");
    return map[y * width + x];
}

Organism *World::GetOrganism(int x, int y) {
    return GetTile(x, y).GetOrganism();
}

bool World::IsOccupied(int x, int y) {
    return GetTile(x, y).IsOccupied();
}

void World::AddOrganism(Organism *organism) {
    organisms.push_back(organism);
    Tile &tile = GetTile(organism->getX(), organism->getY());
    if(tile.IsOccupied())
        throw std::runtime_error("Tile is already occupied");
    tile.SetOrganism(organism);
}

int World::GetWidth() {
    return width;
}

int World::GetHeight() {
    return height;
}

void World::Save(std::ofstream &file) {
    throw;
}

void World::Load(std::ifstream &file) {\
    throw;
}

void World::MoveOrganism(Organism *organism, int x, int y) {
    if(x < 0 || x >= width || y < 0 || y >= height)
        throw std::runtime_error("Invalid coordinates");
    Tile &tile = GetTile(x, y);
    if(tile.IsOccupied())
        throw std::runtime_error("Tile is already occupied");
    Tile &oldTile = GetTile(organism->getX(), organism->getY());
    oldTile.SetOrganism(nullptr);
    tile.SetOrganism(organism);
    organism->setX(x);
    organism->setY(y);
}

void World::Update() {
    // sort organisms by initiative
    std::sort(organisms.begin(), organisms.end(), [](Organism* a, Organism* b) {
        if(a->getInitiative() == b->getInitiative())
            return a->getAge() > b->getAge();
        return a->getInitiative() > b->getInitiative();
    });
    std::vector<Organism*> temp = organisms;
    for(Organism* organism : temp) {
        organism->Action();
        organism->setAge(organism->getAge() + 1);
    }
}

void World::Randomize() {
    int organismsCount = width * height / 50 + 5;
    for(int i = 0; i < organismsCount; i++) {
        int x = rand() % width;
        int y = rand() % height;
        if(IsOccupied(x, y))
            continue;
        int type = rand() % typeCount;
        switch(type) {
            case 0:
                AddOrganism(new Sheep(x, y, this));
                break;
            case 1:
                AddOrganism(new Wolf(x, y, this));
                break;
            case 2:
                AddOrganism(new Grass(x, y, this));
                break;
        }
    }
}
