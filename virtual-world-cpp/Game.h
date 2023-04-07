#pragma once
#include "VirtualWorld/World.h"
#include "VirtualWorld/Animals/Human.h"
#include <string>

class Game {
private:
    World* world = nullptr; bool running = true;
    Human* player = nullptr;
    int playerX = 0, playerY = 0;
    void Initialize();
    void Load(std::string filename);
    void Save(std::string filename);
    void NewGame();
    void Turn();
    void Print();
    void Input();
    void Update();
public:
    Game();
    ~Game();
    void Run();
};
