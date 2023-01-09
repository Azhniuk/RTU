import java.awt.*;
import java.awt.Dimension;

import javax.swing.*;

public class Panel extends JPanel{

    Image backgroundImage;

    Panel(){
       // this.setPreferredSize(new Dimension(500, 500));
        this.setBackground(Color.BLACK);

        backgroundImage = new ImageIcon("bg.jpg").getImage();            

    }

    public void paint(Graphics g){

        super.paint(g);
        
        Graphics2D g2D = (Graphics2D) g;
        g2D.drawImage(backgroundImage, 0, 0, null);
    }


    
}

