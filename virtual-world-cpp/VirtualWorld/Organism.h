#pragma once
#include <fstream>

class Organism {
protected:
    int x, y;
    int strength;
    int initiative;
    int age;
    char symbol;
    void* world;
public:
    Organism(int x, int y, int strength, int initiative, int age, char symbol, void* world);
    virtual void Action() = 0;
    virtual void Collision(Organism &other) = 0;
    virtual bool AttackPaired(Organism &attacker) = 0;
    virtual void Save(std::ofstream& file) = 0;
    virtual void Load(std::ifstream& file) = 0;
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getStrength() const;
    int getInitiative() const;
    int getAge() const;
    void setAge(int age);
    char getSymbol() const;
};
