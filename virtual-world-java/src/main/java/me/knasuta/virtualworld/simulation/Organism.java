package me.knasuta.virtualworld.simulation;

import java.awt.Color;

public abstract class Organism {
    protected Point location;
    protected int strength;
    protected int initiative;
    protected int age;
    protected World world;
    protected boolean alive;


    public Organism(Point location, int strength, int initiative, int age, World world) {
        this.location = location;
        this.strength = strength;
        this.initiative = initiative;
        this.age = age;
        this.world = world;
        this.alive = true;
    }

    public abstract void Action();
    public void Collision(Organism other){
        boolean thisWon = true;
        if(this == other)
            return;
        if(other.AttackPaired(this))
            return;
        if(this.strength < other.strength)
            thisWon = false;
        else if(this.strength == other.strength && other.getAge() > this.getAge())
            thisWon = false;
        if(thisWon || !other.IsAlive()){
            this.world.RemoveOrganism(other);
            this.world.MoveOrganism(this, other.getLocation());
            this.world.AddMessage(other.getName() + " was eaten by " + this.getName() + " at " + other.getLocation().toString());
        }
        else{
            this.world.RemoveOrganism(this);
            this.world.AddMessage(this.getName() + " was killed by " + other.getName() + " at " + other.getLocation().toString());
        }
    }
    public abstract boolean AttackPaired(Organism other);
    public abstract String getName();
    public abstract Organism Clone(Point location, World world);
    public int getX() {
        return location.getX();
    }
    public int getY() {
        return location.getY();
    }
    public void setX(int x) {
        this.location.setX(x);
    }
    public void setY(int y) {
        this.location.setY(y);
    }
    public Point getLocation() {
        return location;
    }
    public void setLocation(Point location) {
        this.location = location;
    }
    public int getStrength() {
        return strength;
    }
    public void setStrength(int strength) {
        this.strength = strength;
    }
    public int getInitiative() {
        return initiative;
    }
    public void setInitiative(int initiative) {
        this.initiative = initiative;
    }
    public int getAge() {
        return age;
    }
    public void setAge(int age) {
        this.age = age;
    }
    public abstract Color getColor();
    public boolean IsAlive() {
        return alive;
    }
    public void Kill() {
        this.alive = false;
    }

    public static class Comparator implements java.util.Comparator<Organism> {
        @Override
        public int compare(Organism o1, Organism o2) {
            if(o1.getInitiative() > o2.getInitiative()) {
                return -1;
            } else if(o1.getInitiative() < o2.getInitiative()) {
                return 1;
            } else {
                if(o1.getAge() > o2.getAge()) {
                    return -1;
                } else if(o1.getAge() < o2.getAge()) {
                    return 1;
                } else {
                    return 0;
                }
            }
        }
    }
}
