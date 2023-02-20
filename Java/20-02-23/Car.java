import java.util.Random;
import java.util.Scanner; 

public class Car {

    int wheeles = 4; 
    String engine = "gasoline";
    int consume = 20, vol = 30; //L/100 km

    public void drive(int dis, int cons, int vol, double price) {  
        float a;
        a = dis / 100 * cons;
        System.out.println(vol/price);
        if (a<=vol){
            System.out.println("Enough to drive the distance");
        }
        else{
            System.out.println("Not enough to drive the distance");
        }

    }
    public static void main(String[] args) {
        Random rand = new Random();

        Car opel = new Car();
        opel.consume = 7;

        Car audi= new Car();
        audi.consume = 10;

        int distance = rand.nextInt(1000); 
        System.out.println("FOR OPEL. Price engine is: ");
        opel.drive(distance, opel.consume, Gasoline.vol, Gasoline.price);
        System.out.println("FOR AUDI. Price engine is: ");
        opel.drive(distance, audi.consume, Disel.vol,  Disel.price);

}
}
 
