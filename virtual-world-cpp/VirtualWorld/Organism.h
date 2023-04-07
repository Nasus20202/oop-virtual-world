#pragma once
#include <fstream>

class Organism {
protected:
    int x, y;
    int strength;
    int initiative;
    int age;
    char symbol;
    void* world; // World* world; must be cast to World* in every method because of circular dependency
    bool alive = true;
public:
    virtual ~Organism();
    Organism(int x, int y, int strength, int initiative, int age, char symbol, void* world);
    virtual void Action() = 0;
    virtual void Collision(Organism *other);
    virtual bool AttackPaired(Organism *attacker) = 0;
    virtual std::string GetName() = 0;
    virtual Organism* Clone(int x, int y, void* world) = 0;
    void Save(std::ofstream& file);
    void Load(std::ifstream& file);
    int getX() const;
    void setX(int x);
    int getY() const;
    void setY(int y);
    int getStrength() const;
    int getInitiative() const;
    int getAge() const;
    void setAge(int age);
    char getSymbol() const;
    void Kill();
    bool IsAlive();
};
