#include "Wolf.h"

Wolf::Wolf(int x, int y, void* world):
        Animal(x, y, 9, 5, 0, 'W', world) {}

void Wolf::Action() {

}

void Wolf::Collision(Organism &other) {

}

bool Wolf::AttackPaired(Organism &attacker) {
    return false;
}

void Wolf::Save(std::ofstream &file) {

}

void Wolf::Load(std::ifstream &file) {

}

void Wolf::Move() {

}

void Wolf::Breed() {

}
