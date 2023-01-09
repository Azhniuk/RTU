
import javax.swing.JButton;
import javax.swing.JFrame;


/*import java.awt.*;
import java.awt.event.*;
import javax.swing.*;*/


public class Frame extends JFrame {


    public static void main(String[] args) {

    }

    Panel panel;
    JButton b;
    


    Frame(){

        panel = new Panel();

        JButton b = new JButton();
        
       b.setBounds(50, 100, 150, 100);
       b.setSize(100, 50);
       ///b.addActionListener(this);
       b.setText("   A ти коцик ♥   ");   



        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		//this.setLayout(null);
		this.setSize(500,500);
		this.setVisible(true);

        this.add(panel);
       // this.pack();
        this.setLocationRelativeTo(null);

      

		this.add(b);
		//this.add(label);


}




}