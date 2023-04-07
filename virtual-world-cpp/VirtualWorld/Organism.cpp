#include <string>
#include "Organism.h"
#include "World.h"


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

void Organism::Save(std::ofstream &file) {

}

void Organism::Load(std::ifstream &file) {

}

void Organism::Collision(Organism* other) {
    World *w = (World *) this->world;
    bool thisWin = true;
    if(this == other)
        return;
    if(other->AttackPaired(this))
        return;
    if(other->getStrength() > this->getStrength())
        thisWin = false;
    else if(other->getStrength() == this->getStrength() && other->getAge() > this->getAge())
        thisWin = false;
    if(thisWin || other->getAge() == -1){
        w->RemoveOrganism(other);
        w->MoveOrganism(this, other->getX(), other->getY());
        if(other->GetName() != "Grass")
            w->AddMessage(this->GetName() + " killed " + other->GetName());
    } else {
        w->RemoveOrganism(this);
        w->AddMessage(other->GetName() + " killed " + this->GetName());
    }
}

void Organism::Kill() {
    this->alive = false;
}

bool Organism::IsAlive() {
    return alive;
}

Organism::~Organism() = default;
