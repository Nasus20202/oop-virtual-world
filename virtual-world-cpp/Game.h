#pragma once
#include "VirtualWorld/World.h"
#include <string>

class Game {
private:
    World* world = nullptr;
    void Initialize();
    void Load(std::string filename);
    void Save(std::string filename);
    void NewGame();
public:
    Game();
    ~Game();
    void Run();
};
