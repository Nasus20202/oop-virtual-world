#include "Game.h"
#include <iostream>
using namespace std;

Game::Game() {

}

Game::~Game() {
    delete world;
}

void Game::Run() {
    Initialize();
}

void Game::Initialize() {
    bool loadGame = false;
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
        NewGame();
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
}
