package me.knasuta.virtualworld.gui;

import me.knasuta.virtualworld.simulation.MovementType;
import me.knasuta.virtualworld.simulation.World;
import me.knasuta.virtualworld.simulation.animals.Human;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;

public class MainWindow extends JFrame {
    private World world;
    private int width = 1280;
    private int height = 720;
    private String title = "Virtual World - Krzysztof Nasuta 193328";
    private JPanel rightPanel, leftPanel, bottomPanel;
    private Map map;
    private JScrollPane scrollPane;
    private JMenuBar menuBar;
    private JMenuItem loadButton, saveButton, newGameButton;
    private JButton nextTurnButton, abilityButton;
    private JLabel abilityLabel;
    private JComboBox directionComboBox;

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
        scrollPane = new JScrollPane(map);
        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);

        leftPanel.setPreferredSize(new Dimension(200, 0));
        rightPanel.setPreferredSize(new Dimension(300, 0));
        bottomPanel.setPreferredSize(new Dimension(0, 50));
        this.add(this.leftPanel, BorderLayout.WEST);
        this.add(this.rightPanel, BorderLayout.EAST);
        this.add(this.bottomPanel, BorderLayout.SOUTH);
        this.add(scrollPane, BorderLayout.CENTER);

        nextTurnButton = new JButton("Next turn");
        nextTurnButton.addActionListener(e -> NextTurn());
        bottomPanel.add(nextTurnButton);

        logs = new TextArea("",39, 30, TextArea.SCROLLBARS_VERTICAL_ONLY);
        logs.setEditable(false);
        logs.setFocusable(false);
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

        directionComboBox = new JComboBox();
        bottomPanel.add(directionComboBox);

        abilityButton = new JButton("Use shield");
        abilityButton.addActionListener(e -> UseAbility());
        bottomPanel.add(abilityButton);

        abilityLabel = new JLabel();
        bottomPanel.add(abilityLabel);

        KeyboardFocusManager keyboardFocusManager = KeyboardFocusManager.getCurrentKeyboardFocusManager();
        keyboardFocusManager.addKeyEventDispatcher(new KeyboardDispatcher());

        setVisible(true);
    }

    private void UseAbility(){
        if(world == null)
            return;
        Human player = world.getPlayer();
        if(!player.IsAlive()){
            JOptionPane.showMessageDialog(this, "You are dead!", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        if(!player.isAbilityReady()){
            JOptionPane.showMessageDialog(this, "Ability is not ready yet! Wait for " + player.getAbilityCooldown() + " turns." , "Error", JOptionPane.ERROR_MESSAGE);
        } else {
            world.getPlayer().UseAbility();
        }
    }

    private void NewGame() {
        NewGameWindow newGameWindow = new NewGameWindow(this);
    }
    public void NewGameCallback(int width, int height, boolean hex){
        world = new World(width, height, hex);
         PrepareForNewGame();
    }
    private void PrepareForNewGame(){
        world.AddStartingOrganisms();
        map.setWorld(world);
        scrollPane.revalidate();
        scrollPane.repaint();
        directionComboBox.removeAllItems();
        String[] directions;
        if(world.IsHexagonal()){
            directions = new String[]{"NONE (R)","UP LEFT (Q)", "UP RIGHT (W)", "LEFT (A)", "RIGHT (S)", "DOWN LEFT (Z)", "DOWN RIGHT (X)"};
        } else {
            directions = new String[]{"NONE (R)", "UP (W)", "LEFT (A)", "RIGHT (D)", "DOWN (S)"};
        }
        for(String direction : directions){
            directionComboBox.addItem(direction);
        }
        Update();
    }
    private void NextTurn(){
        if(world == null)
            return;
        int direction = directionComboBox.getSelectedIndex();
        MovementType movementType = MovementType.NONE;
        if(world.IsHexagonal()){
            switch (direction) {
                case 1 -> movementType = MovementType.UP_LEFT;
                case 2 -> movementType = MovementType.UP_RIGHT;
                case 3 -> movementType = MovementType.LEFT;
                case 4 -> movementType = MovementType.RIGHT;
                case 5 -> movementType = MovementType.DOWN_LEFT;
                case 6 -> movementType = MovementType.DOWN_RIGHT;

            }
        } else {
            switch (direction) {
                case 1 -> movementType = MovementType.UP;
                case 2 -> movementType = MovementType.LEFT;
                case 3 -> movementType = MovementType.RIGHT;
                case 4 -> movementType = MovementType.DOWN;
            }
        }
        world.getPlayer().setDirection(movementType);
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
        Human player = world.getPlayer();
        String abilityText;
        if(!player.IsAlive()){
            abilityText = "You are dead!";
        } else {
            if(player.isAbilityActive()){
                abilityText = "Ability active! Active for " + player.getAbilityDuration() + " turns.";
            } else if(player.isAbilityReady()){
                abilityText = "Ability ready!";
            } else {
                abilityText = "Ability not ready! Wait for " + player.getAbilityCooldown() + " turns.";
            }
        }
        abilityLabel.setText(abilityText);
    }

    private void HandleKeyPress(KeyEvent e){
        if(world == null)
            return;
        if(world.IsHexagonal()) {
            switch (e.getKeyCode()) {
                case KeyEvent.VK_SPACE -> Update();
                case KeyEvent.VK_R -> directionComboBox.setSelectedIndex(0);
                case KeyEvent.VK_Q -> directionComboBox.setSelectedIndex(1);
                case KeyEvent.VK_W -> directionComboBox.setSelectedIndex(2);
                case KeyEvent.VK_A -> directionComboBox.setSelectedIndex(3);
                case KeyEvent.VK_S -> directionComboBox.setSelectedIndex(4);
                case KeyEvent.VK_Z -> directionComboBox.setSelectedIndex(5);
                case KeyEvent.VK_X -> directionComboBox.setSelectedIndex(6);
            }
        } else {
            switch (e.getKeyCode()) {
                case KeyEvent.VK_SPACE -> Update();
                case KeyEvent.VK_R -> directionComboBox.setSelectedIndex(0);
                case KeyEvent.VK_W -> directionComboBox.setSelectedIndex(1);
                case KeyEvent.VK_A -> directionComboBox.setSelectedIndex(2);
                case KeyEvent.VK_D -> directionComboBox.setSelectedIndex(3);
                case KeyEvent.VK_S -> directionComboBox.setSelectedIndex(4);
            }
        }
    }
    private class KeyboardDispatcher implements KeyEventDispatcher {
        @Override
        public boolean dispatchKeyEvent(KeyEvent e) {
            if (e.getID() == KeyEvent.KEY_PRESSED)
                HandleKeyPress(e);
            return false;
        }
    }
}

