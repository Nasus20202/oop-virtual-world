package me.knasuta.virtualworld.simulation.plants;

import me.knasuta.virtualworld.simulation.Organism;
import me.knasuta.virtualworld.simulation.Point;
import me.knasuta.virtualworld.simulation.World;
import me.knasuta.virtualworld.simulation.animals.Animal;

import java.awt.*;
import java.util.Vector;

public class SosnowskysHogweed extends Plant {
    public SosnowskysHogweed(Point location, World world) {
        super(location, 10, 0, world);
    }
    @Override
    public String getName() {
        return "Sosnowsky's Hogweed";
    }

    @Override
    public Organism Clone(Point location, World world) {
        return new SosnowskysHogweed(location, world);
    }

    @Override
    public Color getColor() {
        return Color.PINK;
    }

    @Override
    public void Action(){
        super.Action();
        Vector<Point> neighbours = world.GetAdjacentPoints(this.getLocation());
        for(Point point : neighbours){
            Organism organism = world.getOrganism(point);
            if(organism instanceof Animal) {
                organism.Kill();
                world.RemoveOrganism(organism);
                world.AddMessage(organism.getName() + " was killed by toxic pine borscht");
            }
        }
    }

    @Override
    public boolean AttackPaired(Organism other) {
        other.Kill();
        world.RemoveOrganism(other);
        world.AddMessage(other.getName() + " ate pine borscht and died");
        return super.AttackPaired(other);
    }
}
