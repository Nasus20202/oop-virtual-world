package me.knasuta.virtualworld.simulation.animals;

import me.knasuta.virtualworld.simulation.*;

public abstract class Animal extends Organism {
    protected static int BREEDING_AGE = 5;
    public Animal(Point location, int strength, int initiative, int age, World world){
        super(location, strength, initiative, age, world);
    }

    public boolean TryToBreed(Organism other){
        if(this.getClass() == other.getClass()){
            if(this.age >= BREEDING_AGE && other.getAge() >= BREEDING_AGE){
                Point childLocation = this.world.GetRandomAdjacentPoint(this.location);
                if(childLocation != null){
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
