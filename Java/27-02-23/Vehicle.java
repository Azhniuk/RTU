import java.util.Scanner; 

abstract class Vehicle {
  public static void main(String[] args){
    Car car = new Car();
    Bus bus = new Bus();

    System.out.println("Gasoline price:");
    Scanner scan = new Scanner(System.in);  
    Float price = scan.nextFloat(); 
    scan.close();

    car.showExpences(price, car.CONSUMPTION, car.NAME);
    bus.showExpences(price, bus.CONSUMPTION, bus.NAME);
  }
  
  public void showExpences(Float price, int cons, String name){
    System.out.println("For "+name+" 155 km: "+ 155 / 100 * cons * price+" EUR");
    return;
    }    
}



class Car extends Vehicle{ 
  final String NAME = "Car";  
  final Integer CONSUMPTION = 16;
}

class Bus extends Vehicle {
  final String NAME = "Bus";  
  final Integer CONSUMPTION = 24;  
}




