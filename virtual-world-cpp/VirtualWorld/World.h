#pragma once
#include <vector>
#include "Tile.h"

class World {
private:
    int width, height;
    std::vector<Tile> map;
    std::vector<Organism*> organisms;
    std::vector<std::string> messages;
public:
    World(int width, int height);
    ~World();
    void Empty();
    void Print(int x, int y, int range);
    Tile* GetTile(int x, int y);
    Organism* GetOrganism(int x, int y);
    std::vector<Organism*> &GetOrganisms();
    bool IsOccupied(int x, int y);
    void AddOrganism(Organism* organism);
    void RemoveOrganism(Organism* organism);
    void MoveOrganism(Organism* organism, int x, int y);
    int GetWidth();
    int GetHeight();
    void Save(std::ofstream& file);
    void Load(std::ifstream& file);
    void Update();
    void RemoveDead();
    void Randomize();
    void AddMessage(const std::string& message);
    std::vector<std::string>& GetMessages();
    void ClearMessages();
};
