package me.knasuta.virtualworld.gui;

import me.knasuta.virtualworld.simulation.World;

import javax.swing.*;
import java.awt.*;

public class MainWindow extends JFrame {
    private World world;
    private int width = 1680;
    private int height = 1260;
    private String title = "Virtual World - Krzysztof Nasuta 193328";
    private JPanel rightPanel, leftPanel, bottomPanel;
    private Map map;
    private JMenuBar menuBar;
    private JMenuItem loadButton, saveButton, newGameButton;
    public MainWindow() {
        InitComponents();
    }

    private void InitComponents() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(width, height);
        setTitle(title);
        setVisible(true);
        setLayout(new BorderLayout());

        this.rightPanel = new JPanel();
        this.leftPanel = new JPanel();
        this.bottomPanel = new JPanel();
        this.map = new Map();
        leftPanel.setPreferredSize(new Dimension(200, 0));
        rightPanel.setPreferredSize(new Dimension(200, 0));
        bottomPanel.setPreferredSize(new Dimension(0, 50));
        this.add(this.leftPanel, BorderLayout.WEST);
        this.add(this.rightPanel, BorderLayout.EAST);
        this.add(this.bottomPanel, BorderLayout.SOUTH);
        this.add(this.map, BorderLayout.CENTER);

        menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");
        newGameButton = new JMenuItem("New Game");
        newGameButton.addActionListener(e -> NewGame());
        loadButton = new JMenuItem("Load");
        saveButton = new JMenuItem("Save");
        fileMenu.add(newGameButton);
        fileMenu.add(loadButton);
        fileMenu.add(saveButton);
        menuBar.add(fileMenu);
        this.setJMenuBar(menuBar);
    }

    protected void NewGame() {
        NewGameWindow newGameWindow = new NewGameWindow(this);
    }
    public void NewGameCallback(int width, int height, boolean hex){
        world = new World(width, height, hex);
        world.AddStartingOrganisms();
        map.setWorld(world);
        UpdateMap();
    }

    private void UpdateMap() {
        map.invalidate();
        map.validate();
        map.repaint();
    }
}

