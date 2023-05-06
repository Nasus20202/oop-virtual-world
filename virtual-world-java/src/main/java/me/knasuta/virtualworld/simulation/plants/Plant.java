package me.knasuta.virtualworld.simulation.plants;

import me.knasuta.virtualworld.simulation.Organism;
import me.knasuta.virtualworld.simulation.Point;
import me.knasuta.virtualworld.simulation.World;

public abstract class Plant extends Organism {
    @Override
    public void Action(){
        Point newLocation = world.GetRandomAdjacentPoint(this.location);
        if(newLocation != null){
            Organism other = world.getOrganism(newLocation);
            if(other == null) {
                world.AddOrganism(this.Clone(newLocation, world));
            }
        }
    }
    public Plant(Point location, int strength, int initiative, int age, World world){
        super(location, strength, initiative, age, world);
    }

    @Override
    public boolean AttackPaired(Organism other){
        return false;
    }
}
