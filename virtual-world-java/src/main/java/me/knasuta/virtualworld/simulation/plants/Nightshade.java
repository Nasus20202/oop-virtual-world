package me.knasuta.virtualworld.simulation.plants;

import me.knasuta.virtualworld.simulation.Organism;
import me.knasuta.virtualworld.simulation.Point;
import me.knasuta.virtualworld.simulation.World;

import java.awt.*;

public class Nightshade extends Plant {
    public Nightshade(Point location, World world) {
        super(location, 99, 0, world);
    }
    @Override
    public boolean AttackPaired(Organism other) {
        other.Kill();
        this.Kill();
        world.RemoveOrganism(other);
        world.RemoveOrganism(this);
        world.AddMessage(other.getName() + " ate nightshade and died");
        return true;
    }

    @Override
    public String getName() {
        return "Nightshade";
    }

    @Override
    public Organism Clone(Point location, World world) {
        return new Nightshade(location, world);
    }

    @Override
    public Color getColor() {
        return Color.BLACK;
    }
}
