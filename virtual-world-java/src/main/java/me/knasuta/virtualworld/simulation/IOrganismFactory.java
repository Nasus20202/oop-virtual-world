package me.knasuta.virtualworld.simulation;

public interface IOrganismFactory {
    Organism Create(OrganismType type, Point position, World world);
}
