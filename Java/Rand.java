import java.util.Random;
import java.util.Scanner; 

public class Rand {
    public static void main(String[] args) {
        
        Random rand = new Random();
        Scanner scan = new Scanner(System.in); 

        int num1 = rand.nextInt(11); 
        int num2 = rand.nextInt(11); 
        int answer = num1 * num2;
        System.out.println("First: "+num1+". Second: "+num2+". What is the result of multiplication of that numbers?");
        Integer answ = scan.nextInt();
        
        if (answ == answer ){
            System.out.println("Yess!!");
        }
        else{
            System.out.println("Noo");
        }

        


    

}
}
 
