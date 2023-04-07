#include "Wolf.h"

Wolf::Wolf(int x, int y):
        Animal(x, y, 9, 5, 0, 'W') {}

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
