package me.knasuta.virtualworld.simulation.animals;

import me.knasuta.virtualworld.simulation.*;
import me.knasuta.virtualworld.simulation.Point;

import java.awt.*;

public class Sheep extends Animal {
    public Sheep(Point location, World world){
        super(location, 4, 4, 0, world);
    }


    @Override
    public boolean AttackPaired(Organism other) {
        return false;
    }

    @Override
    public String getName() {
        return "Sheep";
    }

    @Override
    public Organism Clone(Point location, World world) {
        return new Sheep(location, world);
    }

    @Override
    public Color getColor() {
        return Color.WHITE;
    }
}
