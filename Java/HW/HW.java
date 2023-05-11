import javax.swing.*;  
import java.awt.*;


import java.awt.FlowLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;


public class HW implements ActionListener 
{  
    Color myWhite = new Color(205, 255, 255);
    JFrame frame = new JFrame("24-04");  
    JTextField t1,t2, t3;  
    JLabel label = new JLabel();
    JLabel label1 = new JLabel();
    JLabel label2 = new JLabel();
     

    public HW() {
        JRadioButton add = new JRadioButton("Add");
        JRadioButton subtract = new JRadioButton("Subtract");
        JRadioButton multiply = new JRadioButton("Multiply");
        
        JButton calculate =new JButton("Calculate");  
    
    
    
        frame.setSize(300, 300);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLocationRelativeTo(null);
        frame.setLayout(null);   
    
        label.setText("Number 1");
        label.setBounds(15,10,70,25);
        label1.setText("Number 2");
        label1.setBounds(15,35,70,25);
        label2.setText("Number 3");
        label2.setBounds(15,60,70,25);
     
     
        //ввід тексту
        t1=new JTextField("");  
        t1.setBounds(90, 12, 150,20);  
        t2=new JTextField("");  
        t2.setBounds(90,35, 150,20); 
        t3=new JTextField("");  
        t3.setBounds(90,60, 150,20); 
        
        add.setBounds(10, 110, 58, 20);
        subtract.setBounds(90, 110, 90, 20);
        multiply.setBounds(190, 110, 70, 20);
    
       
        calculate.setBounds(15, 190, 250, 40);
        calculate.setBackground(myWhite);
        calculate.setFont(new Font("TimesRoman", Font.PLAIN, 20)); 
        calculate.addActionListener(this);
    
    
        frame.add(label);
        frame.add(label1);
        frame.add(label2);
        frame.add(t1); 
        frame.add(t2);  
        frame.add(t3); 
        frame.add(add);
        frame.add(subtract);   
        frame.add(multiply); 
        frame.add(calculate);   
    
        frame.setVisible(true);
    }



    @Override
    public void actionPerformed(ActionEvent e) {
        System.out.println("You have clicked the button");
    }
     
    public static void main(String args[]){
        HW test = new HW();
    }
}