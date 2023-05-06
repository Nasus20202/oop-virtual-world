package me.knasuta.virtualworld.gui;

import me.knasuta.virtualworld.simulation.Organism;
import me.knasuta.virtualworld.simulation.World;

import javax.swing.*;
import java.awt.*;

public class Map extends JPanel {
    private static int organismSize = 10;
    World world;
    public Map() {
        super();
        this.world = null;
    }
    public Map(World world) {
        super();
        this.world = world;
    }
    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        if (this.world != null) {
            DrawWorld(g);
        }
    }

    private void DrawWorld(Graphics g) {
        for(Organism organism : this.world.getOrganisms()) {
            if(world.IsHexagonal()){
                // TODO draw hexagonal world
            } else {
                int x = organism.getLocation().getX() * organismSize;
                int y = organism.getLocation().getY() * organismSize;
                g.setColor(organism.getColor());
                g.fillRect(x, y, organismSize, organismSize);
            }
        }
    }

    public void setWorld(World world) {
        this.world = world;
    }
}
