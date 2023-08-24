import java.awt.*;
import javax.swing.*;

public class frame_settings extends JFrame{
    public static void main(String[] args) {
    }

    Panel panel;

    frame_settings(String string){

        panel = new Panel();

        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.add(panel);
        this.pack();
        this.setLocationRelativeTo(null);
        this.setVisible(true);

        
    }

    }

  



