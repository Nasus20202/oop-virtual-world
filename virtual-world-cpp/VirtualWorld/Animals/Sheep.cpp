#include "Sheep.h"

Sheep::Sheep(int x, int y):
Animal(x, y, 4, 4, 0, 'S') {}

void Sheep::Action() {

}

void Sheep::Collision(Organism &other) {

}

bool Sheep::AttackPaired(Organism &attacker) {
    return false;
}

void Sheep::Save(std::ofstream &file) {

}

void Sheep::Load(std::ifstream &file) {

}

void Sheep::Move() {

}

void Sheep::Breed() {

}
