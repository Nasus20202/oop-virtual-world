package me.knasuta.virtualworld.simulation.plants;

import me.knasuta.virtualworld.simulation.Organism;
import me.knasuta.virtualworld.simulation.Point;
import me.knasuta.virtualworld.simulation.World;

import java.awt.*;

public class Dandelion extends Plant {
    public Dandelion(Point location, World world) {
        super(location, 0, 0, world);
    }
    @Override
    public String getName() {
        return "Dandelion";
    }

    @Override
    public Organism Clone(Point location, World world) {
        return new Dandelion(location, world);
    }

    @Override
    public Color getColor() {
        return Color.YELLOW;
    }

    @Override
    public void Action(){
        for(int i = 0; i < 3; i++)
            super.Action();
    }
}
