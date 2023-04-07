#include "Game.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "VirtualWorld/AllOgranisms.h"
using namespace std;

void Game::Turn() {
    Update();
    ClearScreen();
    Print();
    Input();
}

void Game::Print() {
    //cout << "Krzysztof Nasuta 193328\t\tControls: WASD - move, SPACE - pass, Q - quit, E - special ability, L - load, 0 - save\n\n" << endl;
    if(alive)
        cout << "X: " << player->getX() << " Y: " << player->getY() << "\t\t\tTurn: " << round << endl;
    else
        cout << "\t\tYou died!" << endl;
    world->Print(currentX, currentY, viewRange);
    cout << endl;
    world->ClearMessages();
}

void Game::Update() {
    round++;
    if(alive) {
        player->Move(moveX, moveY);
        currentX = player->getX();
        currentY = player->getY();
    }
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
    FILE* file;
    fopen_s(&file, filename.c_str(), "rb");
    if(file == nullptr) {
        cout << "File not found!" << endl;
        Input();
        return;
    }
    int width, height, organismsCount;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    NewGame(width, height);
    fread(&round, sizeof(int), 1, file);
    fread(&alive, sizeof(bool), 1, file);
    fread(&currentX, sizeof(int), 1, file);
    fread(&currentY, sizeof(int), 1, file);
    fread(&organismsCount, sizeof(int), 1, file);
    for(int i = 0; i < organismsCount; i++) {
        char type;
        fread(&type, sizeof(char), 1, file);
        Organism* organism = nullptr;
        switch(type) {

        }
        organism->Load(file);
        world->AddOrganism(organism);
    }
}

void Game::Save(std::string filename) {
    FILE* file;
    fopen_s(&file, filename.c_str(), "wb");
    if(file == nullptr){
        cout << "Error while saving!" << endl;
        Input();
        return;
    }
    int width = world->GetWidth(), height = world->GetHeight(), organismsCount = world->GetOrganisms().size();
    fwrite(&width, sizeof(int), 1, file);
    fwrite(&height, sizeof(int), 1, file);
    fwrite(&round, sizeof(int), 1, file);
    fwrite(&alive, sizeof(bool), 1, file);
    fwrite(&currentX, sizeof(int), 1, file);
    fwrite(&currentY, sizeof(int), 1, file);
    fwrite(&organismsCount, sizeof(int), 1, file);
    for(auto organism : world->GetOrganisms()) {
        char type = organism->getSymbol();
        fwrite(&type, sizeof(char ), 1, file);
        organism->Save(file);
    }

}

void Game::NewGame(int width, int height) {
    ClearScreen();
    delete world;
    if(width == -1 || height == -1) {
        //cout << "Enter width: ";
        //cin >> width;
        //cout << "Enter height: ";
        //cin >> height;
    }
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
