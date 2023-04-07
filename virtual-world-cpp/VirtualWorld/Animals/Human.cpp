#include "Human.h"

Human::Human(int x, int y) : Animal(x, y, 5, 4, 0, 'X') {

}

void Human::Action() {

}

void Human::Collision(Organism &other) {

}

bool Human::AttackPaired(Organism &attacker) {
    return false;
}

void Human::Breed() {
    return; // human cannot breed
}

void Human::Move() {
    return; // human is controlled by player
}

void Human::Save(std::ofstream &file) {

}

void Human::Load(std::ifstream &file) {

}

void Human::SpecialAbility() {

}
