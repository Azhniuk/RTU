
import javax.swing.*;

public class integer extends HW{
    public static boolean isInteger(JTextField textField) {
        try {
            Integer.parseInt(textField.getText());
            return true;
        } catch (NumberFormatException e) {
            return false;
        }
    }}