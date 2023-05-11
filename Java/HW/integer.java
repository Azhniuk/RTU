
import javax.swing.*;

public class integer{
    public static boolean isInteger(JTextField textField) {
        try {
            Integer.parseInt(textField.getText());
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }}