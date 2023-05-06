package me.knasuta.virtualworld.simulation.plants;

import me.knasuta.virtualworld.simulation.Organism;
import me.knasuta.virtualworld.simulation.Point;
import me.knasuta.virtualworld.simulation.World;

import java.awt.*;

public class Grass extends Plant {
    public Grass(Point location, World world){
        super(location, 0, 0, world);
    }

    @Override
    public String getName(){
        return "Grass";
    }

    @Override
    public Organism Clone(Point location, World world){
        return new Grass(location, world);
    }

    @Override
    public Color getColor() {
        return new Color(0, 128, 0);
    }
}
