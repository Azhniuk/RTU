import java.awt.*;
import java.awt.event.*;
import javax.swing.*;


public class HW implements ActionListener 
{  
    Color myWhite = new Color(205, 255, 255);
    JFrame frame = new JFrame("24-04");  
    JTextField t1,t2, t3;  
    JLabel label = new JLabel();
    JLabel label1 = new JLabel();
    JLabel label2 = new JLabel();

    private ButtonGroup buttonGroup;
     

    public HW() {
        JRadioButton add = new JRadioButton("Add");
        add.setActionCommand("+");
        JRadioButton subtract = new JRadioButton("Subtract");
        subtract.setActionCommand("-");
        JRadioButton multiply = new JRadioButton("Multiply");
        multiply.setActionCommand("*");
        
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


        buttonGroup = new ButtonGroup();
 
        //add radio buttons
        buttonGroup.add(add);
        buttonGroup.add(multiply);
        buttonGroup.add(subtract);
    
        frame.setVisible(true);
    }



    @Override
    public void actionPerformed(ActionEvent e) {
       // String a = t1.getText();

        if (t1.getText().isEmpty() || t2.getText().isEmpty() || t3.getText().isEmpty()) {
            JOptionPane.showMessageDialog(null, "Enter three numbers", "Error", JOptionPane.ERROR_MESSAGE);
        } 
        
        
        
        else {
            int num1 = Integer.parseInt(t1.getText());
            int num2 = Integer.parseInt(t2.getText());
            int num3 = Integer.parseInt(t3.getText());
            int result = 0;

            String selection = buttonGroup.getSelection().getActionCommand();

            if (selection == "+"){ 
                result = num1+num2+num3;
            }else if (selection == "-"){
                result = num1-num2-num3;
            }
            else{
                System.out.println("Select an action");                
            }

            System.out.println(result);

           
        }

        }
      
     
    public static void main(String args[]){
        HW test = new HW();
    }
}