package me.knasuta.virtualworld.gui;

import javax.swing.*;
import javax.swing.filechooser.FileNameExtensionFilter;
import java.io.File;

public class ChooseSaveFileDialog extends JFileChooser {
    String extension;
    public ChooseSaveFileDialog(String title, String extension) {
        super(".");
        this.extension = extension;
        setDialogTitle(title);
        setFileSelectionMode(JFileChooser.FILES_ONLY);
        setAcceptAllFileFilterUsed(false);
        setFileFilter(new FileNameExtensionFilter("Virtual World save file (*." + extension + ")", extension));
    }

    @Override
    public File getSelectedFile() {
        File file = super.getSelectedFile();
        if(file == null)
            return null;
        if(!file.getAbsoluteFile().toString().endsWith("." + extension)){
            file = new File(file.getAbsoluteFile() + "." + extension);
        }
        return file;
    }
}
