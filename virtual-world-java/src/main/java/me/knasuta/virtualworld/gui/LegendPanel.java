package me.knasuta.virtualworld.gui;

import me.knasuta.virtualworld.simulation.*;
import me.knasuta.virtualworld.simulation.Point;
import me.knasuta.virtualworld.simulation.animals.Human;

import javax.swing.*;
import java.awt.*;

public class LegendPanel extends JPanel {
    public LegendPanel() {
        super();
        setLayout(new GridLayout(0, 1));

        JLabel title = new JLabel("Legend:");
        title.setHorizontalAlignment(SwingConstants.CENTER);
        add(title);

        IOrganismFactory factory = OrganismFactory.getInstance();
        for(OrganismType type : OrganismType.values()){
            Organism organism = factory.Create(type, new Point(0, 0), null);
            Label label = new Label(organism.getName(), organism.getColor());
            add(label);
        }

        Human human = new Human(new Point(0, 0), null);
        Label label = new Label(human.getName(), human.getColor());
        add(label);


    }

    private static class Label extends JLabel{
        public Label(String text, Color color){
            super(text);
            setHorizontalAlignment(SwingConstants.CENTER);
            setOpaque(true);
            setPreferredSize(new Dimension(0, 10));
            setBackground(color);
            int colorValue = color.getRed() + color.getGreen() + color.getBlue();
            setForeground(colorValue > 382 ? Color.BLACK : Color.WHITE);
        }
    }
}
