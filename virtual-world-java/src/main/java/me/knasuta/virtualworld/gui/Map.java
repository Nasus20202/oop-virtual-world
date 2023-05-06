package me.knasuta.virtualworld.gui;

import me.knasuta.virtualworld.simulation.World;

import javax.swing.*;

public class Map extends JPanel {
    World world;
    public Map() {
        super();
        this.world = null;
    }
    public Map(World world) {
        super();
        this.world = world;
    }
}
