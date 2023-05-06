package me.knasuta.virtualworld.gui;

import javax.swing.*;
import java.awt.*;

public class MainWindow {
    int width = 1680;
    int height = 1260;
    String title = "Virtual World - Krzysztof Nasuta 193328";
    JFrame frame;
    JPanel rightPanel, leftPanel, bottomPanel;
    JPanel map;
    public MainWindow() {
        this.frame = new JFrame(title);
        this.frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.frame.setSize(width, height);
        this.frame.setVisible(true);
        this.frame.setLayout(new BorderLayout());
        this.rightPanel = new JPanel();
        this.leftPanel = new JPanel();
        this.bottomPanel = new JPanel();
        this.map = new JPanel();
        this.frame.add(this.rightPanel, BorderLayout.EAST);
        this.frame.add(this.leftPanel, BorderLayout.WEST);
        this.frame.add(this.bottomPanel, BorderLayout.SOUTH);
        this.frame.add(this.map, BorderLayout.CENTER);
        InitComponents();
    }

    private void InitComponents() {

    }
}
