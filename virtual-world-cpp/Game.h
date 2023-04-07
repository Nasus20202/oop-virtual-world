#pragma once
#include "VirtualWorld/World.h"
#include "VirtualWorld/Animals/Human.h"
#include <string>

class Game {
private:
    static const int viewRange = 10;
    World* world = nullptr; bool running = true, alive;
    Human* player = nullptr; int round = 0;
    int moveX = 0, moveY = 0;
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
