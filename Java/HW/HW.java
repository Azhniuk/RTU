import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class HW implements ActionListener 
{  
    Color myWhite = new Color(220, 255, 255);
    JFrame frame = new JFrame("24-04");  
    JTextField t1,t2, t3;  
    JLabel label = new JLabel();
    JLabel label1 = new JLabel();
    JLabel label2 = new JLabel();
    JLabel result_Label = new JLabel();

    private ButtonGroup buttonGroup;
     
    public HW() {
//FRAME     
        frame.setSize(300, 300);
        frame.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
        frame.addWindowListener(new CustomWindowAdapter());
        frame.setLocationRelativeTo(null);
        frame.setLayout(null);   
        frame.getContentPane().setBackground(Color.WHITE);
    
//NUMBERS
        label.setText("Number 1");
        label1.setText("Number 2");
        label2.setText("Number 3");
        result_Label.setText("Result: no result");

        label.setBounds(15,10,70,25);
        label1.setBounds(15,40,70,25);
        label2.setBounds(15,70,70,25);
        result_Label.setBounds(25,140,200,40);


        label.setFont(new Font("Courier", Font.PLAIN, 15)); 
        label1.setFont(new Font("Courier", Font.PLAIN, 15)); 
        label2.setFont(new Font("Courier", Font.PLAIN, 15)); 
        result_Label.setFont(new Font("Courier", Font.PLAIN, 18)); 
     
//INPUT
        t1=new JTextField("");  
        t2=new JTextField("");  
        t3=new JTextField("");  

        t1.setBounds(100, 12, 150,20);  
        t2.setBounds(100,45, 150,20); 
        t3.setBounds(100,75, 150,20); 

//ACTION
        JRadioButton add = new JRadioButton("Add");
        JRadioButton subtract = new JRadioButton("Subtract");
        JRadioButton multiply = new JRadioButton("Multiply");
        
        add.setBounds(15, 110, 50, 20);
        subtract.setBounds(80, 110, 85, 20);
        multiply.setBounds(180, 110, 90, 20);

        add.setFont(new Font("Courier", Font.PLAIN, 12)); 
        subtract.setFont(new Font("Courier", Font.PLAIN, 12)); 
        multiply.setFont(new Font("Courier", Font.PLAIN, 12)); 

        add.setBackground(myWhite);
        subtract.setBackground(myWhite);
        multiply.setBackground(myWhite);

//CALCULATE
        JButton calculate =new JButton("Calculate");  
       
        calculate.setBounds(15, 190, 250, 40);
        calculate.setBackground(myWhite);
        calculate.setFont(new Font("TimesRoman", Font.PLAIN, 20)); 
        calculate.addActionListener(this);

//ADD
        buttonGroup = new ButtonGroup();
        buttonGroup.add(add);
        buttonGroup.add(multiply);
        buttonGroup.add(subtract);
    
        frame.add(label);
        frame.add(label1);
        frame.add(label2);
        frame.add(result_Label);
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
        if (t1.getText().isEmpty() || t2.getText().isEmpty() || t3.getText().isEmpty()) {
            JOptionPane.showMessageDialog(null, "Enter three numbers", "Error", JOptionPane.ERROR_MESSAGE);
        }
        else if (notInteger(t1) || notInteger(t2)||notInteger(t3)) {
            System.out.println("Values MUST be INTEGERS");
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
            else if (selection == "*"){
                result = num1*num2*num3;
            }
            else{
                System.out.println("Select an action");                
            }

            System.out.println(result);

           
        }
        }
      


    class CustomWindowAdapter extends WindowAdapter {
            @Override
            public void windowClosing(WindowEvent e) {
                int option = JOptionPane.showConfirmDialog(frame, "Are you sure you want to close the program?", "Confirmation", JOptionPane.YES_NO_OPTION);
                if (option == JOptionPane.YES_OPTION) {
                    frame.dispose();
                }
            }
        }
    
    public static boolean notInteger(JTextField textField) {
            try {
                Integer.parseInt(textField.getText());
                return false;
            } catch (NumberFormatException e) {
                return true;
            }
        }



    public static void main(String args[]){
        HW test = new HW();
        
    }
}