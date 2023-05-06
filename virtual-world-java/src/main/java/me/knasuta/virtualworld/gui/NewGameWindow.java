package me.knasuta.virtualworld.gui;

import javax.swing.*;
import java.awt.*;

public class NewGameWindow  extends JFrame{
    private int width = 400;
    private int height = 300;
    private String title = "New Game";
    private MainWindow mainWindow;
    JTextField widthField, heightField;
    JCheckBox hexCheckBox;


    public NewGameWindow(MainWindow mainWindow) {
        setSize(width, height);
        setTitle(title);
        setResizable(false);
        setVisible(true);
        this.mainWindow = mainWindow;

        setLayout(new GridLayout(4, 2));

        JLabel widthLabel = new JLabel("Width");
        add(widthLabel);
        widthField = new JTextField();
        widthField.setText("20");
        add(widthField);

        JLabel heightLabel = new JLabel("Height");
        add(heightLabel);
        heightField = new JTextField();
        heightField.setText("20");
        add(heightField);

        JLabel hexLabel = new JLabel("Hexagonal");
        add(hexLabel);
        hexCheckBox = new JCheckBox();
        add(hexCheckBox);

        JButton cancelButton = new JButton("Cancel");
        cancelButton.addActionListener(e -> dispose());
        add(cancelButton);

        JButton submitButton = new JButton("Submit");
        submitButton.addActionListener(e -> Submit());
        add(submitButton);
    }

    private void Submit() {
        try {
            int width = Integer.parseInt(widthField.getText());
            int height = Integer.parseInt(heightField.getText());
            if(width < 1 || height < 1) throw new NumberFormatException();
            boolean hex = hexCheckBox.isSelected();
            mainWindow.NewGameCallback(width, height, hex);
        } catch (NumberFormatException e) {
            JOptionPane.showMessageDialog(this, "Invalid width or height", "Error", JOptionPane.ERROR_MESSAGE);
            return;
        }
        dispose();
    }

}
