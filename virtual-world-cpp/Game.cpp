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
    world->Print(moveX, moveY, viewRange);
}

void Game::Update() {
    player->Move(moveX, moveY);
    world->Update();
}

void Game::Input() {
    bool done = false;
    moveX = 0, moveY = 0;
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
            moveY = -1;
        else if (input == 'a')
            moveX = -1;
        else if (input == 's')
            moveY = 1;
        else if (input == 'd')
            moveX = 1;
        else if (input != ' ')
            done = false;
    }
}

Game::Game() {
    srand(time(nullptr));
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
    player = new Human(width/2, height/2, world);
    world->AddOrganism(player);
    world->Randomize();
}

void Game::ClearScreen() {
    system("cls");
}
