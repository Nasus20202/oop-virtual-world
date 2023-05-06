package me.knasuta.virtualworld.simulation.animals;

import me.knasuta.virtualworld.simulation.Organism;
import me.knasuta.virtualworld.simulation.Point;
import me.knasuta.virtualworld.simulation.World;

import java.awt.*;
import java.util.Random;

public class Antelope extends Animal {
    public Antelope(Point location, World world) {
        super(location, 4, 4, 0, world);
    }

    @Override
    public boolean AttackPaired(Organism other) {
        int random = new Random().nextInt(2);
        if (random != 0) {
            Point point = world.GetRandomAdjacentPoint(location);
            if (point != null) {
                world.MoveOrganism(this, point);
                world.AddMessage(this.getName() + " escaped from " + other.getName() + " at " + location.toString());
                return true;
            }
        }
        return false;

    }

    @Override
    public String getName() {
        return "Antelope";
    }

    @Override
    public Organism Clone(Point location, World world) {
        return new Antelope(location, world);
    }

    @Override
    public Color getColor() {
        return new Color(186, 165, 137);
    }
}
