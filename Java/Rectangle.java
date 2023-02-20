import java.util.Scanner; 

public class Rectangle {
    static void beep(String[] args) {
        System.out.println("BEEP");
    }
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in); 
        System.out.println("x: ");
        Integer x = scan.nextInt();
        System.out.println("y: ");
        Integer y = scan.nextInt();
        if(x == y){
            beep(args);
        }
    }
    
}
