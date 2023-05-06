package me.knasuta.virtualworld.simulation.animals;

import me.knasuta.virtualworld.simulation.Organism;
import me.knasuta.virtualworld.simulation.Point;
import me.knasuta.virtualworld.simulation.World;

import java.awt.*;
import java.util.Random;

public class Fox extends Animal {
    public Fox(Point location, World world) {
        super(location, 3, 7, 0, world);
    }

    @Override
    public boolean AttackPaired(Organism other) {
        return false;
    }
    @Override
    public void Action(){
        Point newLocation = world.GetRandomAdjacentPoint(this.location);
        if(newLocation != null){
            Organism other = world.getOrganism(newLocation);
            if(other == null) {
                world.MoveOrganism(this, newLocation);
            } else {
                if(this.getStrength() >= other.getStrength() || other instanceof Fox)
                    Collision(other);
                else
                    world.AddMessage("Fox's great smell saved him from " + other.getName() + " at " + location.toString());
            }
        }
    }

    @Override
    public String getName() {
        return "Fox";
    }

    @Override
    public Organism Clone(Point location, World world) {
        return new Fox(location, world);
    }

    @Override
    public Color getColor() {
        return new Color(255, 140, 0);
    }
}
