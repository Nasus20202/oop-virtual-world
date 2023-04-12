#pragma once
#include "Animal.h"
class Human : public Animal {
    int moveX = 0, moveY = 0; // Used for moving
    const int abilityCooldownMax = 5, abilityDurationMax = 5;
    int abilityCooldown = 0, abilityDuration = 0;
public:
    Human(int x, int y, World* world);
    void Action() override;
    void Collision(Organism *other) override;
    bool AttackPaired(Organism *attacker) override;
    bool TryToBreed(Organism *other) override;
    void Save(FILE* file) override;
    void Load(FILE* file) override;
    bool ShieldActive();
    bool SpecialAbility();
    int GetAbilityCooldown();
    int GetAbilityDuration();
    void Move(int x, int y);
    std::string GetName() override;
    Organism* Clone(int x, int y, World* world) override;
};
