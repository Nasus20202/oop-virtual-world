#include "Human.h"

Human::Human(int x, int y, World* world) : Animal(x, y, 5, 4, 0, humanCode, world) {
}
void Human::Action() {
    int newX = this->x + moveX, newY = this->y + moveY;
    if (newX < 0 || newX >= world->GetWidth() || newY < 0 || newY >= world->GetHeight())
        return;
    if (world->GetOrganism(newX, newY) == nullptr)
        world->MoveOrganism(this, newX, newY);
    else
        this->Collision(world->GetOrganism(newX, newY));
    if(abilityDuration > 0) {
        abilityDuration--;
    }
    if(abilityCooldown > 0) {
        abilityCooldown--;
    }
}

void Human::Collision(Organism* other) {
    if(this->AttackPaired(other))
        return;
    Animal::Collision(other);
}

bool Human::AttackPaired(Organism *attacker) {
    bool isAnimal = dynamic_cast<Animal*>(attacker) != nullptr;
    if(isAnimal && abilityDuration > 0) {
        world->AddMessage("Human's shield saved him from " + attacker->GetName() + "!");
        return true;
    }
    return false;
}

bool Human::SpecialAbility() {
    if(abilityCooldown > 0) {
        return false;
    }
    abilityDuration = abilityDurationMax;
    abilityCooldown = abilityCooldownMax + abilityDuration;
    return true;
}

void Human::Move(int x, int y) {
    moveX = x, moveY = y;
}

bool Human::TryToBreed(Organism *other) {
    return false;
}

std::string Human::GetName() {
    return "Human";
}

Organism *Human::Clone(int x, int y, World *world) {
    return nullptr;
}

void Human::Save(FILE *file) {
    fwrite(&abilityDuration, sizeof(int), 1, file);
    fwrite(&abilityCooldown, sizeof(int), 1, file);
    Organism::Save(file);
}

void Human::Load(FILE *file) {
    fread(&abilityDuration, sizeof(int), 1, file);
    fread(&abilityCooldown, sizeof(int), 1, file);
    Organism::Load(file);
}

bool Human::ShieldActive() {
    return abilityDuration > 0;
}

int Human::GetAbilityCooldown() {
    return abilityCooldown;
}

int Human::GetAbilityDuration() {
    return abilityDuration;
}
