package me.knasuta.virtualworld.simulation.animals;

import me.knasuta.virtualworld.simulation.*;

public abstract class Animal extends Organism {
    protected static int BREEDING_AGE = 1;
    public Animal(Point location, int strength, int initiative, int age, World world){
        super(location, strength, initiative, age, world);
    }

    public boolean TryToBreed(Organism other){
        if(this.getClass() == other.getClass()){
            if(this.age >= BREEDING_AGE && other.getAge() >= BREEDING_AGE){
                Point childLocation = this.world.GetRandomAdjacentPoint(this.location);
                if(childLocation != null){
                    Organism organism = this.world.getOrganism(childLocation);
                    if(organism instanceof Animal) // if there is already an animal at the child location, don't breed
                        return true;
                    if(organism != null)
                        this.world.RemoveOrganism(organism);
                    world.AddOrganism(this.Clone(childLocation, world));
                    world.AddMessage("New " + getName() + " was born at " + childLocation.toString());
                }
            }
            return true;
        }
        return false;
    }

    @Override
    public void Collision(Organism other){
        if(this == other)
            return;
        if(TryToBreed(other))
            return;
        else
            super.Collision(other);
    }

    @Override
    public void Action(){
        Point newLocation = world.GetRandomAdjacentPoint(this.location);
        if(newLocation != null){
            Organism other = world.getOrganism(newLocation);
            if(other == null) {
                world.MoveOrganism(this, newLocation);
            } else {
                Collision(other);
            }
        }
    }
}
