package me.knasuta.virtualworld.simulation.plants;

import me.knasuta.virtualworld.simulation.Organism;
import me.knasuta.virtualworld.simulation.Point;
import me.knasuta.virtualworld.simulation.World;

import java.awt.*;

public class Guarana extends Plant{
    @Override
    public boolean AttackPaired(Organism other) {
        other.setStrength(other.getStrength() + 3);
        world.AddMessage(other.getName() + " ate guarana and gained 3 strength");
        return false;
    }
    public Guarana(Point location, World world) {
        super(location, 0, 0, world);
    }
    @Override
    public String getName() {
        return "Guarana";
    }

    @Override
    public Organism Clone(Point location, World world) {
        return new Guarana(location, world);
    }

    @Override
    public Color getColor() {
        return new Color(255, 0, 255);
    }
}
