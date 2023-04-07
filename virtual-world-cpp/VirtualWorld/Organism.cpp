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

void Organism::Save(FILE* file) {
    fwrite(&x, sizeof(int), 1, file);
    fwrite(&y, sizeof(int), 1, file);
    fwrite(&strength, sizeof(int), 1, file);
    fwrite(&initiative, sizeof(int), 1, file);
    fwrite(&age, sizeof(int), 1, file);
}

void Organism::Load(FILE* file) {
    fread(&x, sizeof(int), 1, file);
    fread(&y, sizeof(int), 1, file);
    fread(&strength, sizeof(int), 1, file);
    fread(&initiative, sizeof(int), 1, file);
    fread(&age, sizeof(int), 1, file);
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
        w->AddMessage(other->GetName()+ " was eaten by " + this->GetName() + " at " + std::to_string(other->getX()) + " " + std::to_string(other->getY()));
    } else {
        w->RemoveOrganism(this);
        w->AddMessage(this->GetName() + " was killed by " + other->GetName() + " at " + std::to_string(this->getX()) + " " + std::to_string(this->getY()));
    }
}

void Organism::Kill() {
    this->alive = false;
}

bool Organism::IsAlive() {
    return alive;
}

void Organism::setStrength(int strength) {
    this->strength = strength;
}

Organism::~Organism() = default;
