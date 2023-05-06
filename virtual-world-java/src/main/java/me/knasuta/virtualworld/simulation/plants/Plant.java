package me.knasuta.virtualworld.simulation.plants;

import me.knasuta.virtualworld.simulation.Organism;
import me.knasuta.virtualworld.simulation.Point;
import me.knasuta.virtualworld.simulation.World;

import java.util.Random;

public abstract class Plant extends Organism {
    static int SEEDING_PROBABILITY = 3;
    @Override
    public void Action(){
        if(new Random().nextInt(SEEDING_PROBABILITY) != 0)
            return;
        Point newLocation = world.GetRandomAdjacentPoint(this.location);
        if(newLocation != null){
            Organism other = world.getOrganism(newLocation);
            if(other == null) {
                world.AddOrganism(this.Clone(newLocation, world));
            }
        }
    }
    public Plant(Point location, int strength, int age, World world){
        super(location, strength, 0, age, world);
    }

    @Override
    public boolean AttackPaired(Organism other){
        return false;
    }
}
