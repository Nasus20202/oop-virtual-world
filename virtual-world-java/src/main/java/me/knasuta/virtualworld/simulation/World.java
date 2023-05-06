package me.knasuta.virtualworld.simulation;

import java.util.Vector;

public class World {
    private int width;
    private int height;
    private Vector<Organism> organisms;
    private Vector<String> messages;
    private Organism[][] organismMap;
    private int turn;
    boolean hexagonal;

    public void Update(){
        this.turn++;
        this.ClearMessages();
        this.organisms.sort(new Organism.Comparator());
        for(Organism organism : this.organisms) {
            if(organism.IsAlive())
                organism.Action();
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
    public boolean IsOccupied(int x, int y) {
        return this.organismMap[x][y] != null;
    }
    public void AddOrganism(Organism organism) {
        this.organisms.add(organism);
        this.organismMap[organism.getX()][organism.getY()] = organism;
    }
    public void RemoveOrganism(Organism organism) {
        this.organisms.remove(organism);
        this.organismMap[organism.getX()][organism.getY()] = null;
    }
    public void MoveOrganism(Organism organism, int x, int y) throws Exception {
        if(this.IsOccupied(x, y)) {
            throw new Exception("Cannot move organism to occupied space");
        }
        this.organismMap[organism.getX()][organism.getY()] = null;
        this.organismMap[x][y] = organism;
        organism.setX(x);
        organism.setY(y);
    }
    public void MoveOrganism(Organism organism, Point point) throws Exception {
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
                this.RemoveOrganism(this.organisms.get(i));
                i--;
            }
        }
    }

    public Point GetRandomAdjacentPoint(Point location) {
        Vector<Point> adjacentPoints = new Vector<Point>();
        for(int x = location.getX() - 1; x <= location.getX() + 1; x++) {
            for(int y = location.getY() - 1; y <= location.getY() + 1; y++) {
                if(x >= 0 && x < this.width && y >= 0 && y < this.height && (x != location.getX() || y != location.getY())) {
                    if(this.hexagonal && (x == location.getX() - 1 && y == location.getY() + 1 || x == location.getX() + 1 && y == location.getY() - 1))
                        continue;
                    if(!this.IsOccupied(x, y)) {
                        adjacentPoints.add(new Point(x, y));
                    }
                }
            }
        }
        if(adjacentPoints.size() == 0) {
            return null;
        }
        return adjacentPoints.get((int)(Math.random() * adjacentPoints.size()));
    }
}
