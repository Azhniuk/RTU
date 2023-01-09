import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class Panel extends JPanel implements ActionListener {

    final int PANEL_WIDTH = 500;
    final int PANEL_HEIDHT = 500;

   // Image flower;
	Image backgroundImage;
	Timer timer;

    int xVelocity = 5;
    int yVelocity = 2;
    int x = 0;
    int y = 0;




    Panel(){
        this.setPreferredSize(new Dimension(PANEL_WIDTH, PANEL_HEIDHT));
        this.setBackground(Color.BLUE);

 

      //  flower = new ImageIcon("flower.png").getImage();
        backgroundImage = new ImageIcon("bg.jpg").getImage();            
        timer = new Timer(10, this);
        timer.start();
      
        
         
         

    }



    public void paint(Graphics g){

        super.paint(g);
        
        Graphics2D g2D = (Graphics2D) g;
        g2D.drawImage(backgroundImage, 0, 0, null);
       // g2D.drawImage(flower, x, y, null);

    }





   @Override
    public void actionPerformed(ActionEvent e) {
        /*if (x>=PANEL_WIDTH - flower.getWidth(null) || x<0){
            xVelocity = xVelocity * -1;
                }
        x = x + xVelocity;


        if (y>=PANEL_HEIDHT - flower.getWidth(null) || y<0){
            yVelocity = yVelocity * -1;
                }
        y = y + yVelocity;
        repaint();
        
*/  
    }




}