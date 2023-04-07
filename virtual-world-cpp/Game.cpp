#include "Game.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "VirtualWorld/AllOgranisms.h"
using namespace std;

void Game::Turn() {
    ClearScreen();
    if(alive)
        Update();
    Print();
    Input();
}

void Game::Print() {
    //cout << "Krzysztof Nasuta 193328\t\tControls: WASD - move, SPACE - pass, Q - quit, E - special ability, L - load, 0 - save\n\n" << endl;
    if(alive) {
        cout << "X: " << player->getX() << " Y: " << player->getY() << "\t\t\tTurn: " << round << endl;
        world->Print(player->getX(), player->getY(), viewRange);
        world->ClearMessages();
    }
    else {
        cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\t\tYou died!" << endl;
    }
}

void Game::Update() {
    round++;
    player->Move(moveX, moveY);
    world->Update();
    if(!player->IsAlive())
        alive = false;
    world->RemoveDead();
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
    int width = 20, height = 20;
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
    alive = true;
    round = 0;
}

void Game::ClearScreen() {
    system("cls");
}
