#include "Game.h"
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include "VirtualWorld/AllOgranisms.h"
using namespace std;

void Game::Turn() {
    if(round != 0) {
        Update();
    } else
        round++;
    ClearScreen();
    Print();
    Input();
}

void Game::Print() {
    cout << "Krzysztof Nasuta 193328\t\tControls: WASD - move, SPACE - pass, Q - quit, E - special ability, L - load, O - save\n\n" << endl;
    if(alive)
        cout << "X: " << player->getX() << " Y: " << player->getY() << "\t\t\tTurn: " << round << (player->ShieldActive() ? "\t\tShielded for " + std::to_string(player->GetAbilityDuration()) : "");
    else
        cout << "\t\tYou died!\t Turn: " << round;
    cout << "\t\tOrganisms: " << world->GetOrganismCount() << endl;
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
            cout << "SAVE | Enter filename: ";
            cin >> filename;
            Save(filename);
        } else if (input == 'l') {
            string filename;
            cout << "LOAD | Enter filename: ";
            cin >> filename;
            Load(filename);
        } else if (input == 'w') {
            moveY = -1; currentY--;
        }
        else if (input == 'a') {
            moveX = -1; currentX--;
        }
        else if (input == 's') {
            moveY = 1; currentY++;
        }
        else if (input == 'd') {
            moveX = 1; currentX++;
        }
        else if (input == 'e' && alive) {
            if(!player->SpecialAbility()){
                cout << "You can't use special ability! Wait " << player->GetAbilityCooldown() << " turns" << endl;
            } else {
                cout << "Shield activated for " << std::to_string(player->GetAbilityDuration()) << " turns!" << endl;
            }
            Input();
        }
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
    ClearScreen();
    cout << "\n\n\tLoad game? (y/n): ";
    char input = _getch();
    if(input == 'y'){
        string filename;
        cout << "\n\tEnter filename: ";
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
        if(world == nullptr)
            Initialize();
        Input();
        return;
    }
    int width, height, organismsCount;
    fread(&width, sizeof(int), 1, file);
    fread(&height, sizeof(int), 1, file);
    NewWorld(width, height);
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
            case humanCode:
                organism = new Human(0, 0, world);
                player = (Human*)organism; break;
            case sheepCode:
                organism = new Sheep(0, 0, world); break;
            case turtleCode:
                organism = new Turtle(0, 0, world); break;
            case wolfCode:
                organism = new Wolf(0, 0, world); break;
            case foxCode:
                organism = new Fox(0, 0, world); break;
            case antelopeCode:
                organism = new Antelope(0, 0, world); break;
            case dandelionCode:
                organism = new Dandelion(0, 0, world); break;
            case guaranaCode:
                organism = new Guarana(0, 0, world); break;
            case grassCode:
                organism = new Grass(0, 0, world); break;
            case nightshadeCode:
                organism = new Nightshade(0, 0, world); break;
            case sosnowskyHogweedCode:
                organism = new SosnowskysHogweed(0, 0, world); break;
            case cyberSheepCode:
                organism = new CyberSheep(0, 0, world); break;
        }
        organism->Load(file);
        world->AddOrganism(organism);
    }
    fclose(file);
    ClearScreen();
    Print();
    cout << "Game loaded!" << endl;
    Input();
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
        if(!organism->IsAlive())
            continue;
        char type = organism->getSymbol();
        fwrite(&type, sizeof(char), 1, file);
        organism->Save(file);
    }
    fclose(file);
    cout << "Game saved!" << endl;
    Input();
}

void Game::NewGame(int width, int height) {
    ClearScreen();
    if(width == -1 || height == -1) {
        while(true) {
            ClearScreen();
            cout << "\n\n\tNEW GAME | Enter width: ";
            cin >> width;
            if(cin.fail() || width < 1){
                cin.clear();
                cin.ignore();
                continue;
            }
            break;
        }
        while(true) {
            ClearScreen();
            cout << "\n\n\tNEW GAME | Enter height: ";
            cin >> height;
            if(cin.fail() || height < 1){
                cin.clear();
                cin.ignore();
                continue;
            }
            break;
        }

    }
    NewWorld(width, height);
    currentX = width/2;
    currentY = height/2;
    player = new Human(currentX, currentY, world);
    world->AddOrganism(player);
    world->Randomize();
    alive = true;
    round = 0;
}

void Game::ClearScreen() {
    system("cls");
}

void Game::NewWorld(int width, int height) {
    delete world;
    world = new World(width, height);
}
