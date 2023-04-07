#ifndef VIRTUAL_WORLD_ANIMALS_ANIMAL_H
#define VIRTUAL_WORLD_ANIMALS_ANIMAL_H

#include "../Organism.h"

class Animal : public Organism {
protected:
    virtual void Move() = 0;
    virtual void Breed() = 0;
public:
    Animal(int x, int y, int strength, int initiative, int age, char symbol);
};

#endif //VIRTUAL_WORLD_ANIMALS_ANIMAL_H
