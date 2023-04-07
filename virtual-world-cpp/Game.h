#pragma once
#include "VirtualWorld/World.h"
#include "VirtualWorld/Animals/Human.h"
#include <string>

class Game {
private:
    static const int viewRange = 10;
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
    void ClearScreen();
public:
    Game();
    ~Game();
    void Run();
};
