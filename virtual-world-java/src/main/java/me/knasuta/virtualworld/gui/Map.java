package me.knasuta.virtualworld.gui;

import me.knasuta.virtualworld.simulation.Organism;
import me.knasuta.virtualworld.simulation.World;

import javax.swing.*;
import java.awt.*;

public class Map extends JPanel {
    private static final int rectangleSize = 10;
    private static final int hexagonSize = 8;
    World world;
    public Map(World world) {
        super();
        this.world = world;

    }
    public Map() {
        this(null);
    }
    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        if(this.world != null) {
            DrawWorld(g);
        }
    }

    private void DrawWorld(Graphics g) {
        for(Organism organism : this.world.getOrganisms()) {
            if(world.IsHexagonal()){
                int x = hexagonSize +(int)(organism.getX() * hexagonSize * Math.sqrt(3) + organism.getY() * hexagonSize * Math.sqrt(3)/2.0);
                int y = hexagonSize + organism.getY() * hexagonSize * 2;
                DrawHexagon(g, x, y, organism.getColor());
            } else {
                int x = organism.getX() * rectangleSize;
                int y = organism.getY() * rectangleSize;
                g.setColor(organism.getColor());
                g.fillRect(x, y, rectangleSize, rectangleSize);
            }
        }
    }

    private void DrawHexagon(Graphics g, int x, int y, Color color){
        int[] xPoints = new int[6];
        int[] yPoints = new int[6];
        for(int i = 0; i < 6; i++){
            double angle = 2 * Math.PI / 6 * i + Math.PI / 6;
            xPoints[i] = (int) (x + hexagonSize * Math.cos(angle));
            yPoints[i] = (int) (y + hexagonSize * Math.sin(angle));
        }
        g.setColor(color);
        g.fillPolygon(xPoints, yPoints, 6);
    }

    public void setWorld(World world) {
        this.world = world;
    }

    public void Update(){
        this.invalidate();
        this.validate();
        this.repaint();
    }
}
