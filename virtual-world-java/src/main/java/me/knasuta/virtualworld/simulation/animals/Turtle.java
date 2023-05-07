package me.knasuta.virtualworld.simulation.animals;

import me.knasuta.virtualworld.simulation.Organism;
import me.knasuta.virtualworld.simulation.Point;
import me.knasuta.virtualworld.simulation.World;

import java.awt.*;

public class Turtle extends Animal {

    public Turtle(Point location, World world) {
        super(location, 2, 1, 0, world);
    }

    @Override
    public boolean AttackPaired(Organism other) {
        if(other.getStrength() < 5){
            world.AddMessage("Turtle defended itself from " + other.getName() + " at " + this.location.toString());
            return true;
        }
        return false;
    }

    @Override
    public String getName() {
        return "Turtle";
    }

    @Override
    public Organism Clone(Point location, World world) {
        return new Turtle(location, world);
    }

    @Override
    public Color getColor() {
        return Color.GREEN;
    }

    @Override
    public void Action(){
        if(Math.random() < 0.25)
            super.Action();
    }
}
