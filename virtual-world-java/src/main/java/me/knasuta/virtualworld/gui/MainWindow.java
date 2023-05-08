package me.knasuta.virtualworld.gui;

import me.knasuta.virtualworld.simulation.MovementType;
import me.knasuta.virtualworld.simulation.World;
import me.knasuta.virtualworld.simulation.animals.Human;

import javax.swing.*;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.io.File;

public class MainWindow extends JFrame {
    private final String extension = "vws";
    private World world;
    private Map map;
    private JScrollPane scrollPane;
    private JLabel statusLabel;
    private JComboBox<String> directionComboBox;

    private TextArea logs;
    public MainWindow() {
        InitComponents();
    }

    private void InitComponents() {
        int width = 1280;
        int height = 720;
        String title = "Virtual World - Krzysztof Nasuta 193328";
        int legendPanelWidth = 150;
        int rightPanelWidth = 250;
        int bottomPanelHeight = 50;

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(width, height);
        setTitle(title);
        setLayout(new BorderLayout());

        LegendPanel legendPanel = new LegendPanel();
        JPanel rightPanel = new JPanel();
        JPanel bottomPanel = new JPanel();

        this.map = new Map();
        scrollPane = new JScrollPane(map);
        scrollPane.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
        scrollPane.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);

        legendPanel.setPreferredSize(new Dimension(legendPanelWidth, 0));
        rightPanel.setPreferredSize(new Dimension(rightPanelWidth, 0));
        bottomPanel.setPreferredSize(new Dimension(0, bottomPanelHeight));
        this.add(legendPanel, BorderLayout.WEST);
        this.add(rightPanel, BorderLayout.EAST);
        this.add(bottomPanel, BorderLayout.SOUTH);
        this.add(scrollPane, BorderLayout.CENTER);

        JButton nextTurnButton = new JButton("Next turn");
        nextTurnButton.addActionListener(e -> NextTurn());
        bottomPanel.add(nextTurnButton);


        rightPanel.setLayout(new BoxLayout(rightPanel, BoxLayout.Y_AXIS));
        logs = new TextArea( "", 0, 0, TextArea.SCROLLBARS_VERTICAL_ONLY);
        logs.setPreferredSize(new Dimension(rightPanelWidth -10, 0));
        logs.setEditable(false);
        logs.setFocusable(false);
        JScrollPane logsScrollPane = new JScrollPane(logs);
        rightPanel.add(logsScrollPane);

        JMenuBar menuBar = new JMenuBar();
        JMenu fileMenu = new JMenu("File");
        JMenuItem newGameButton = new JMenuItem("New Game");
        newGameButton.addActionListener(e -> NewGame());
        JMenuItem loadButton = new JMenuItem("Load");
        JMenuItem saveButton = new JMenuItem("Save");
        loadButton.addActionListener(e -> LoadGame());
        saveButton.addActionListener(e -> SaveGame());
        fileMenu.add(newGameButton);
        fileMenu.add(loadButton);
        fileMenu.add(saveButton);
        menuBar.add(fileMenu);
        this.setJMenuBar(menuBar);

        directionComboBox = new JComboBox<>();
        bottomPanel.add(directionComboBox);

        JButton abilityButton = new JButton("Use shield");
        abilityButton.addActionListener(e -> UseAbility());
        bottomPanel.add(abilityButton);

        statusLabel = new JLabel();
        bottomPanel.add(statusLabel);

        KeyboardFocusManager keyboardFocusManager = KeyboardFocusManager.getCurrentKeyboardFocusManager();
        keyboardFocusManager.addKeyEventDispatcher(new KeyboardDispatcher());

        setVisible(true);
    }

    private void LoadGame(){
        ChooseSaveFileDialog fileChooser = new ChooseSaveFileDialog("Load game", extension);
        int result = fileChooser.showOpenDialog(this);
        if(result == JFileChooser.APPROVE_OPTION){
            File file = fileChooser.getSelectedFile();
            world = World.Load(file.getAbsolutePath());
            if(world == null){
                JOptionPane.showMessageDialog(this, "Cannot load save", "Error", JOptionPane.ERROR_MESSAGE);
                return;
            }
            PrepareForNewGame();
        }
    }
    private void SaveGame(){
        if(world == null)
            return;
        ChooseSaveFileDialog fileChooser = new ChooseSaveFileDialog("Save game", extension);
        int result = fileChooser.showSaveDialog(this);
        if(result == JFileChooser.APPROVE_OPTION){
            File file = fileChooser.getSelectedFile();
            boolean success = world.Save(file.getAbsolutePath());
            if(!success){
                JOptionPane.showMessageDialog(this, "Cannot save game", "Error", JOptionPane.ERROR_MESSAGE);
            }
        }
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
        UpdateStatusText();
    }

    private void NewGame() {
        NewGameWindow newGameWindow = new NewGameWindow(this);
    }
    public void NewGameCallback(int width, int height, boolean hex){
        world = new World(width, height, hex);
        world.AddStartingOrganisms();
        PrepareForNewGame();
        Update();
    }
    private void PrepareForNewGame(){
        map.setWorld(world);
        scrollPane.revalidate();
        scrollPane.repaint();
        UpdateStatusText();
        UpdateLogs();
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
        UpdateLogs();
        UpdateStatusText();
    }

    public void UpdateLogs(){
        String log = "";
        for(String message : world.getMessages()){
            log += message + '\n';
        }
        logs.setText(log);
    }

    private void UpdateStatusText(){
        Human player = world.getPlayer();
        String abilityText;
        if(!player.IsAlive()){
            abilityText = "You are dead!";
        } else {
            if(player.isAbilityActive()){
                abilityText = "Ability active! Active for " + player.getAbilityDuration() + " turns. ";
            } else if(player.isAbilityReady()){
                abilityText = "Ability ready! ";
            } else {
                abilityText = "Ability not ready! Wait for " + player.getAbilityCooldown() + " turns. ";
            }
            abilityText += "Position: " + player.getLocation().toString() + " Turn: " + (world.getTurn()+1);
        }
        statusLabel.setText(abilityText);
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

