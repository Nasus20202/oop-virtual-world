package me.knasuta.virtualworld.gui;

import me.knasuta.virtualworld.simulation.*;
import me.knasuta.virtualworld.simulation.Point;

import javax.swing.*;
import java.awt.*;

public class AddOrganismWindow  extends JFrame{
    private final World world;
    private final Point position;
    private final Map map;
    private final OrganismNameTypePair[] pairs;
    private final JComboBox<OrganismNameTypePair> organismComboBox;


    public AddOrganismWindow(World world, Point position, Map map) {
        int width = 250;
        int height = 120;
        setSize(width, height);
        setTitle(position.toString());
        setResizable(false);
        setVisible(true);
        this.world = world;
        this.position = position;
        this.map = map;

        setLayout(new GridLayout(3, 1));

        pairs = new OrganismNameTypePair[OrganismType.values().length];
        for(int i = 0; i < OrganismType.values().length; i++){
            OrganismType type = OrganismType.values()[i];
            pairs[i] = new OrganismNameTypePair(OrganismFactory.getInstance().GetName(type), type);
        }
        organismComboBox = new JComboBox<>();
        organismComboBox.setModel(new DefaultComboBoxModel<>(pairs));
        add(organismComboBox);

        JButton submitButton = new JButton("Submit");
        submitButton.addActionListener(e -> Submit());
        JButton cancelButton = new JButton("Cancel");
        cancelButton.addActionListener(e -> dispose());
        add(submitButton);
        add(cancelButton);
    }

    private void Submit() {
        Organism oldOrganism = world.getOrganism(position);
        if(oldOrganism != null){
            world.RemoveOrganism(oldOrganism);
        }
        int selectedIndex = organismComboBox.getSelectedIndex();
        Organism newOrganism = OrganismFactory.getInstance().Create(pairs[selectedIndex].type, position, world);
        world.AddOrganism(newOrganism);
        map.OrganismAddedCallback();
        dispose();
    }

    private static class OrganismNameTypePair {
        public String name;
        public OrganismType type;

        public OrganismNameTypePair(String name, OrganismType type) {
            this.name = name;
            this.type = type;
        }
        @Override
        public String toString() {
            return name;
        }
    }
}
