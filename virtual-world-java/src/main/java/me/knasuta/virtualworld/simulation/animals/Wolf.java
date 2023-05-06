package me.knasuta.virtualworld.simulation.animals;

import me.knasuta.virtualworld.simulation.*;
import me.knasuta.virtualworld.simulation.Point;

import java.awt.*;

public class Wolf extends Animal {
    public Wolf(Point location, World world){
        super(location, 9, 5, 0, world);
    }


    @Override
    public boolean AttackPaired(Organism other) {
        return false;
    }

    @Override
    public String getName() {
        return "Wolf";
    }

    @Override
    public Organism Clone(Point location, World world) {
        return OrganismFactory.getInstance().Create(OrganismType.WOLF, location, world);
    }

    @Override
    public Color getColor() {
        return Color.GRAY;
    }
}
