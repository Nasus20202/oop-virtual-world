#pragma once
#include "TypeCodes.h"
#include "World.h"
#include <string>

class World;

class Organism {
protected:
    int x, y;
    int strength;
    int initiative;
    int age;
    char symbol;
    World* world;
    bool alive = true;
public:
    virtual ~Organism();
    Organism(int x, int y, int strength, int initiative, int age, char symbol, World* world);
    virtual void Action() = 0;
    virtual void Collision(Organism *other);
    virtual bool AttackPaired(Organism *attacker) = 0;
    virtual std::string GetName() = 0;
    virtual Organism* Clone(int x, int y, World* world) = 0;
    virtual void Save(FILE* file);
    virtual void Load(FILE* file);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getStrength() const;
    void setStrength(int strength);
    int getInitiative() const;
    int getAge() const;
    void setAge(int age);
    char getSymbol() const;
    void Kill();
    bool IsAlive();
};
