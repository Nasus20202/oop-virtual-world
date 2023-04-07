#include "Game.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "VirtualWorld/AllOgranisms.h"
using namespace std;

void Game::Turn() {
    ClearScreen();
    Print();
    Input();
    Update();
}

void Game::Print() {
    cout << player->getX() << " " << player->getY() << endl;
    world->Print(playerX, playerY, viewRange);
}

void Game::Update() {
    player->Move(playerX, playerY);
}

void Game::Input() {
    bool done = false;
    while(!done) {
        done = true;
        char input = _getch();
        if (input == 'q')
            running = false;
        else if (input == 'n')
            NewGame();
        else if (input == 'o') {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            Save(filename);
        } else if (input == 'l') {
            string filename;
            cout << "Enter filename: ";
            cin >> filename;
            Load(filename);
        } else if (input == 'w')
            playerY--;
        else if (input == 'a')
            playerX--;
        else if (input == 's')
            playerY++;
        else if (input == 'd')
            playerX++;
        else
            done = false;
    }
    if(playerX < 0)
        playerX = 0;
    if(playerY < 0)
        playerY = 0;
    if(playerX >= world->GetWidth())
        playerX = world->GetWidth() - 1;
    if(playerY >= world->GetHeight())
        playerY = world->GetHeight() - 1;
}

Game::Game() {
}

Game::~Game() {
    delete world;
}

void Game::Run() {
    Initialize();
    while(running)
        Turn();
}

void Game::Initialize() {
    bool loadGame = false;
    //cout << "Load game? (y/n): ";
    char input;
    //cin >> input;
    input = 'n';
    if(input == 'y'){
        string filename;
        cout << "Enter filename: ";
        cin >> filename;
        Load(filename);
    }
    else
        NewGame();
}

void Game::Load(std::string filename) {

}

void Game::Save(std::string filename) {

}

void Game::NewGame() {
    ClearScreen();
    delete world;
    int width, height;
    //cout << "Enter width: ";
    //cin >> width;
    //cout << "Enter height: ";
    //cin >> height;
    width = 25;
    height = 25;
    world = new World(width, height);
    playerX = width / 2;
    playerY = height / 2;
    player = new Human(playerX, playerY, world);
    world->AddOrganism(player);
}

void Game::ClearScreen() {
    system("cls");
}
