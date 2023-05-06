package me.knasuta.virtualworld.gui;

import me.knasuta.virtualworld.simulation.World;

import javax.swing.*;
import java.awt.*;

public class MainWindow extends JFrame {
    private World world;
    private int width = 1280;
    private int height = 720;
    private String title = "Virtual World - Krzysztof Nasuta 193328";
    private JPanel rightPanel, leftPanel, bottomPanel;
    private Map map;
    private JMenuBar menuBar;
    private JMenuItem loadButton, saveButton, newGameButton;
    private JButton nextTurnButton;
    private TextArea logs;
    public MainWindow() {
        InitComponents();
    }

    private void InitComponents() {
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(width, height);
        setTitle(title);
        setLayout(new BorderLayout());

        this.rightPanel = new JPanel();
        this.leftPanel = new JPanel();
        this.bottomPanel = new JPanel();
        this.map = new Map();
        leftPanel.setPreferredSize(new Dimension(200, 0));
        rightPanel.setPreferredSize(new Dimension(300, 0));
        bottomPanel.setPreferredSize(new Dimension(0, 50));
        this.add(this.leftPanel, BorderLayout.WEST);
        this.add(this.rightPanel, BorderLayout.EAST);
        this.add(this.bottomPanel, BorderLayout.SOUTH);
        this.add(this.map, BorderLayout.CENTER);

        nextTurnButton = new JButton("Next turn");
        nextTurnButton.addActionListener(e -> NextTurn());
        bottomPanel.add(nextTurnButton);

        logs = new TextArea("",39, 30, TextArea.SCROLLBARS_VERTICAL_ONLY);
        logs.setEditable(false);
        rightPanel.add(logs);

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

        setVisible(true);
    }

    private void NewGame() {
        NewGameWindow newGameWindow = new NewGameWindow(this);
    }
    public void NewGameCallback(int width, int height, boolean hex){
        world = new World(width, height, hex);
        world.AddStartingOrganisms();
        map.setWorld(world);
        Update();
    }
    private void NextTurn(){
        if(world == null)
            return;
        world.Update();
        Update();
    }
    private void Update(){
        map.Update();
        String log = "";
        for(String message : world.getMessages()){
            log += message + '\n';
        }
        logs.setText(log);
    }
}

