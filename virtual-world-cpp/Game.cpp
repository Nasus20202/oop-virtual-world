#include "Game.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "VirtualWorld/AllOgranisms.h"
using namespace std;

void Game::Turn() {
    system("cls");
    Print();
    Update();
    Input();
}

void Game::Print() {
    world->Print(playerX, playerY, 50);
}

void Game::Update() {

}

void Game::Input() {
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
    }
    else if (input == 'l') {
        string filename;
        cout << "Enter filename: ";
        cin >> filename;
        Load(filename);
    }
    else if (input == 'w')
        playerY--;
    else if (input == 'a')
        playerX--;
    else if (input == 's')
        playerY++;
    else if (input == 'd')
        playerX++;
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
    /*bool loadGame = false;
    cout << "Load game? (y/n): ";
    char input;
    cin >> input;
    if (input == 'y')
        loadGame = true;
    if(loadGame){
        string filename;
        cout << "Enter filename: ";
        cin >> filename;
        Load(filename);
    }
    else
        NewGame();*/
    world = new World(20, 20);
    playerX = 10;
    playerY = 10;
    world->GetTile(playerX, playerY).SetOrganism(new Human(playerX, playerY));
}

void Game::Load(std::string filename) {

}

void Game::Save(std::string filename) {

}

void Game::NewGame() {
    delete world;
    int width, height;
    cout << "Enter width: ";
    cin >> width;
    cout << "Enter height: ";
    cin >> height;
    world = new World(width, height);
    playerX = width / 2;
    playerY = height / 2;
}
