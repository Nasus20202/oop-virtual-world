package me.knasuta.virtualworld.simulation;

import me.knasuta.virtualworld.simulation.animals.*;
import me.knasuta.virtualworld.simulation.plants.*;

public class OrganismFactory implements IOrganismFactory {
    private static OrganismFactory instance = null;
    private final Organism[] organisms;
    private OrganismFactory() {
        organisms = new Organism[OrganismType.values().length];
        organisms[OrganismType.WOLF.ordinal()] = new Wolf(new Point(0, 0), null);
        organisms[OrganismType.SHEEP.ordinal()] = new Sheep(new Point(0, 0), null);
    }

    public static OrganismFactory getInstance() {
        if (instance == null) {
            instance = new OrganismFactory();
        }
        return instance;
    }
    @Override
    public Organism Create(OrganismType type, Point location, World world) {
        return organisms[type.ordinal()].Clone(location, world);
    }
}
