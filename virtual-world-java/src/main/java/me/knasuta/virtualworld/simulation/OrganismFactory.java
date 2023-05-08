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
        organisms[OrganismType.GRASS.ordinal()] = new Grass(new Point(0, 0), null);
        organisms[OrganismType.ANTELOPE.ordinal()] = new Antelope(new Point(0, 0), null);
        organisms[OrganismType.FOX.ordinal()] = new Fox(new Point(0, 0), null);
        organisms[OrganismType.TURTLE.ordinal()] = new Turtle(new Point(0, 0), null);
        organisms[OrganismType.DANDELION.ordinal()] = new Dandelion(new Point(0, 0), null);
        organisms[OrganismType.GUARANA.ordinal()] = new Guarana(new Point(0, 0), null);
        organisms[OrganismType.NIGHTSHADE.ordinal()] = new Nightshade(new Point(0, 0), null);
        organisms[OrganismType.SOSNOWSKY_HOGWEED.ordinal()] = new SosnowskysHogweed(new Point(0, 0), null);
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

    @Override
    public String GetName(OrganismType type) {
        return organisms[type.ordinal()].getName();
    }
}
