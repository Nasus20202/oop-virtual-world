package me.knasuta.virtualworld.simulation;

import me.knasuta.virtualworld.simulation.animals.Human;

import java.util.Vector;

public class World {
    private int width;
    private int height;
    private Vector<Organism> organisms;
    private Vector<String> messages;
    private Organism[][] organismMap;
    private int turn;
    private boolean hexagonal;
    private Human player;

    public Human getPlayer(){
        return player;
    }
    public void Update(){
        this.turn++;
        this.ClearMessages();
        this.organisms.sort(new Organism.Comparator());
        for(int i = 0; i < organisms.size(); i++) {
            Organism organism = organisms.get(i);
            if(organism.IsAlive())
                organism.Action();
            organism.setAge(organism.getAge()+1);
        }
        this.RemoveDeadOrganisms();
    }

    public World(int width, int height, boolean hexagonal) {
        this.width = width;
        this.height = height;
        this.organisms = new Vector<Organism>();
        this.messages = new Vector<String>();
        this.organismMap = new Organism[width][height];
        this.hexagonal = hexagonal;
        this.turn = 0;
    }
    public World(int width, int height) {
        this(width, height, false);
    }
    public Organism getOrganism(int x, int y) throws IndexOutOfBoundsException {
        if(x < 0 || x >= this.width || y < 0 || y >= this.height) {
            throw new IndexOutOfBoundsException("Cannot get organism outside of world");
        }
        return this.organismMap[x][y];
    }
    public Organism getOrganism(Point point){
        return getOrganism(point.getX(), point.getY());
    }
    public boolean IsOccupied(int x, int y) {
        return this.organismMap[x][y] != null;
    }
    public void AddOrganism(Organism organism) {
        if(this.IsOccupied(organism.getX(), organism.getY())) {
            return;
        }
        this.organisms.add(organism);
        this.organismMap[organism.getX()][organism.getY()] = organism;
    }
    public void RemoveOrganism(Organism organism) {
        this.organisms.remove(organism);
        this.organismMap[organism.getX()][organism.getY()] = null;
    }
    public void MoveOrganism(Organism organism, int x, int y)  {
        if(this.IsOccupied(x, y)) {
            return;
        }
        this.organismMap[organism.getX()][organism.getY()] = null;
        this.organismMap[x][y] = organism;
        organism.setX(x);
        organism.setY(y);
    }
    public void MoveOrganism(Organism organism, Point point)  {
        this.MoveOrganism(organism, point.getX(), point.getY());
    }
    public int getWidth() {
        return this.width;
    }
    public int getHeight() {
        return this.height;
    }
    public int getTurn() {
        return this.turn;
    }
    public boolean IsHexagonal() {
        return this.hexagonal;
    }
    public void AddMessage(String message) {
        this.messages.add(message);
    }
    public Vector<String> getMessages() {
        return this.messages;
    }
    public void ClearMessages() {
        this.messages.clear();
    }
    public void RemoveDeadOrganisms() {
        for(int i = 0; i < this.organisms.size(); i++) {
            if(!this.organisms.get(i).IsAlive()) {
                organisms.remove(i);
                i--;
            }
        }
    }
    public Vector<Point> GetAdjacentPoints(Point location){
        Vector<Point> adjacentPoints = new Vector<Point>();
        for(int x = location.getX() - 1; x <= location.getX() + 1; x++) {
            for(int y = location.getY() - 1; y <= location.getY() + 1; y++) {
                if(x >= 0 && x < this.width && y >= 0 && y < this.height && (x != location.getX() || y != location.getY())) {
                    if(this.hexagonal && (x == location.getX() - 1 && y == location.getY() - 1 || x == location.getX() + 1 && y == location.getY() + 1))
                        continue;
                    adjacentPoints.add(new Point(x, y));
                }
            }
        }
        return adjacentPoints;
    }

    public Point GetRandomAdjacentPoint(Point location) {
        Vector<Point> adjacentPoints = this.GetAdjacentPoints(location);
        if(adjacentPoints.size() == 0) {
            return null;
        }
        return adjacentPoints.get((int)(Math.random() * adjacentPoints.size()));
    }

    public void AddStartingOrganisms(){
        int x = (int)(Math.random() * this.width);
        int y = (int)(Math.random() * this.height);
        this.player = new Human(new Point(x, y), this);
        this.AddOrganism(this.player);
        int[] organismCounts = new int[OrganismType.values().length];
        organismCounts[OrganismType.WOLF.ordinal()] = 3;
        organismCounts[OrganismType.SHEEP.ordinal()] = 4;
        organismCounts[OrganismType.GRASS.ordinal()] = 4;
        organismCounts[OrganismType.ANTELOPE.ordinal()] = 4;
        organismCounts[OrganismType.FOX.ordinal()] = 4;
        organismCounts[OrganismType.TURTLE.ordinal()] = 4;
        organismCounts[OrganismType.DANDELION.ordinal()] = 2;
        organismCounts[OrganismType.GUARANA.ordinal()] = 1;
        organismCounts[OrganismType.NIGHTSHADE.ordinal()] = 1;
        organismCounts[OrganismType.SOSNOWSKY_HOGWEED.ordinal()] = 1;
        int baseOrganismCount = (int)(2 + Math.log(width * height) * 0.005f);
        IOrganismFactory factory = OrganismFactory.getInstance();
        for(OrganismType organismType : OrganismType.values()) {
            for(int i = 0; i < organismCounts[organismType.ordinal()]*baseOrganismCount; i++) {
                x = (int)(Math.random() * this.width);
                y = (int)(Math.random() * this.height);
                this.AddOrganism(factory.Create(organismType, new Point(x, y), this));
            }
        }
    }

    public Vector<Organism> getOrganisms() {
        return this.organisms;
    }
}
