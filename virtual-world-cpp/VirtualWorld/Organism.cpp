#include "Organism.h"

Organism::Organism(int x, int y, int strength, int initiative, int age, char symbol, void* world) : x(x), y(y), strength(strength), initiative(initiative), age(age), symbol(symbol), world(world) {
}

int Organism::getX() const {
    return x;
}

void Organism::setX(int x) {
    this->x = x;
}

int Organism::getY() const {
    return y;
}

void Organism::setY(int y) {
    this->y = y;
}

int Organism::getStrength() const {
    return strength;
}

int Organism::getInitiative() const {
    return initiative;
}

int Organism::getAge() const {
    return age;
}

void Organism::setAge(int age) {
    this->age = age;
}

char Organism::getSymbol() const {
    return symbol;
}
