package me.knasuta.virtualworld.simulation.animals;

import me.knasuta.virtualworld.simulation.MovementType;
import me.knasuta.virtualworld.simulation.Organism;
import me.knasuta.virtualworld.simulation.Point;
import me.knasuta.virtualworld.simulation.World;

import java.awt.*;

public class Human extends Animal {
    private int abilityCooldown = 0, abilityDuration = 0;
    static final int abilityCooldownTime = 10, abilityDurationTime = 5;
    private MovementType direction = MovementType.NONE;
    public Human(Point p, World world) {
        super(p, 5, 4, 0, world);
    }

    @Override
    public void Action() {
        int dx = 0, dy = 0;
        switch (direction) {
            case UP -> dy = -1;
            case DOWN -> dy = 1;
            case LEFT -> dx = -1;
            case RIGHT -> dx = 1;
            case UP_LEFT -> {
                dy = -1;
            }
            case UP_RIGHT -> {
                dx = 1;
                dy = -1;
            }
            case DOWN_LEFT -> {
                dx = -1;
                dy = 1;
            }
            case DOWN_RIGHT -> {
                dy = 1;
            }
        }
        abilityCooldown--;
        abilityDuration--;
        int x = getX() + dx, y = getY() + dy;
        if(x < 0 || x >= world.getWidth() || y < 0 || y >= world.getHeight())
            return;
        Point newLocation = new Point(x, y);
        Organism other = world.getOrganism(newLocation);
        if(other == null) {
            world.MoveOrganism(this, newLocation);
        }
        else {
            Collision(other);
        }

    }
    public void setDirection(MovementType direction){
        this.direction = direction;
    }
    public MovementType getDirection(){
        return direction;
    }

    public int getAbilityCooldown() {
        return Math.max(abilityCooldown, 0);
    }
    public int getAbilityDuration() {
        return Math.max(abilityDuration, 0);
    }
    public boolean isAbilityActive() {
        return abilityDuration > 0;
    }
    public boolean isAbilityReady() {
        return abilityCooldown <= 0;
    }
    public void UseAbility(){
        if(abilityCooldown > 0)
            return;
        abilityCooldown = abilityCooldownTime;
        abilityDuration = abilityDurationTime;
    }
    @Override
    public boolean AttackPaired(Organism other) {
        if(isAbilityActive()) {
            world.AddMessage("Human's shield saved him from " + other.getName());
            return true;
        }
        return false;
    }

    @Override
    public String getName() {
        return "Human";
    }

    @Override
    public Organism Clone(Point location, World world) {
        throw new UnsupportedOperationException();
    }

    @Override
    public Color getColor() {
        return Color.BLACK;
    }
}
