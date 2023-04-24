import javax.swing.*;  
import java.awt.*;
class TextFieldExample  
{  
public static void main(String args[])  
    {  
    JFrame frame = new JFrame("24-04");  
    JTextField t1,t2;  
    JLabel label = new JLabel();
    JLabel label1 = new JLabel();
    JRadioButton male = new JRadioButton("Male");
    JRadioButton female = new JRadioButton("Female");
    JCheckBox student = new JCheckBox("Student");
    JCheckBox pensioner = new JCheckBox("Pensioner");
    JButton confirm =new JButton("Confirm");  



    //JPanel panel = new JPanel();


    frame.setSize(300, 300);
    frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
    frame.setLocationRelativeTo(null);
    frame.setLayout(null);   

    label.setText("Name");
    label.setBounds(15,20,50,25);
    label1.setText("Surname");
    label1.setBounds(15,70,50,25);
 
    t1=new JTextField("");  
    t1.setBounds(70, 20, 150,25);  
    t2=new JTextField("");  
    t2.setBounds(70,70, 150,25); 
    
    male.setBounds(10, 120, 58, 20);
    female.setBounds(10, 150, 70, 20);

    student.setBounds(100, 120, 70, 20);
    pensioner.setBounds(100, 150, 100, 20);
    confirm.setBounds(20, 190, 200, 20);
    confirm.setBackground(Color.red);



   // male.setSelected(true);

    frame.add(label);
    frame.add(label1);
    frame.add(t1); 
    frame.add(t2);  
    frame.add(male);
    frame.add(female);    
    frame.add(student); 
    frame.add(pensioner);  
    frame.add(confirm);   

    frame.setVisible(true);


    }  
    }  