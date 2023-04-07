#include "World.h"
#include <iostream>
#include <algorithm>
#include "AllOgranisms.h"

World::World(int width, int height) : width(width), height(height) {
    map.resize(width * height);
}

World::~World() {
    Empty();
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
        std::cout << "\xDB";
        if(itY - startY < messages.size())
            std::cout << "\t" << messages[itY - startY];
        std::cout << std::endl;
    }
    std::cout << "\xDB";
    for(int i = startX; i <= endX; i++)
        std::cout << "\xDC\xDC";
    std::cout << "\xDB";
}

Tile *World::GetTile(int x, int y) {
    if(x < 0 || x >= width || y < 0 || y >= height)
        throw std::runtime_error("Tile out of bounds");
    return &map[y * width + x];
}

Organism *World::GetOrganism(int x, int y) {
    return GetTile(x, y)->GetOrganism();
}

bool World::IsOccupied(int x, int y) {
    return GetTile(x, y)->IsOccupied();
}

void World::AddOrganism(Organism *organism) {
    organisms.push_back(organism);
    Tile *tile = GetTile(organism->getX(), organism->getY());
    if(tile->IsOccupied())
        throw std::runtime_error("Tile is already occupied");
    tile->SetOrganism(organism);
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
    Tile *tile = GetTile(x, y);
    if(tile->IsOccupied())
        throw std::runtime_error("Tile is already occupied");
    Tile *oldTile = GetTile(organism->getX(), organism->getY());
    oldTile->SetOrganism(nullptr);
    tile->SetOrganism(organism);
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
    for(int i = 0; i < organisms.size(); i++) {
        Organism* organism = organisms[i];
        if(!organism->IsAlive())
            continue;
        organism->Action();
        organism->setAge(organism->getAge() + 1);
    }
}

void World::Randomize() {
    const int organismsCount = 2 + sqrt((width + height)/2)*0.6;
    for(int i = 0; i < typeCount; i++){
        for(int j = 0; j < organismsCount; j++) {
            int x = rand() % width;
            int y = rand() % height;
            if(!IsOccupied(x, y)) {
                switch(i) {
                    case 0:
                        AddOrganism(new Sheep(x, y, this)); break;
                    case 1:
                        AddOrganism(new Wolf(x, y, this)); break;
                    case 2:
                        AddOrganism(new Grass(x, y, this)); break;
                }
            }
        }
    }
}

void World::RemoveOrganism(Organism *organism) {
    GetTile(organism->getX(), organism->getY())->SetOrganism(nullptr);
    organism->Kill();
}

void World::Empty() {
    for(Organism* organism : organisms)
        delete organism;
    organisms.clear();
}

void World::RemoveDead() {
    for(int i = 0; i < organisms.size(); i++) {
        if(!organisms[i]->IsAlive()) {
            delete organisms[i];
            organisms.erase(organisms.begin() + i);
            i--;
        }
    }
}

std::vector<std::string> &World::GetMessages() {
    return messages;
}

void World::AddMessage(const std::string& message) {
    messages.push_back(message);
}

void World::ClearMessages() {
    messages.clear();
}
