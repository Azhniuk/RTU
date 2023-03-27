
/// Azhniuk Sofiia Variant 1 id: 221ADB207
import java.util.Scanner;

class Shape {
  public void askNumber(){
    Scanner scan = new Scanner(System.in);  
    System.out.println("Enter first side");

    String side1 = scan.nextLine(); 
    System.out.println("Enter second side");
    String side2 = scan.nextLine(); 

    System.out.println("Enter second side");
    scan.close();

  }
  public void animalSound() {
    System.out.println("The animal makes a sound");
  }
}

class Triangle extends Shape {
  int a, b, c;
  public void animalSound() {
    System.out.println("The pig says: wee wee");
  }
}

class Dog extends Shape {
  public void animalSound() {
    System.out.println("The dog says: bow wow");
  }
}

class Main {
  public static void main(String[] args) {
    Shape shape = new Shape();  // Create a Animal object
    Shape triangle = new Triangle();  // Create a Pig object
    Shape myDog = new Dog();  // Create a Dog object
    shape.animalSound();
    shape.askNumber();
    triangle.animalSound();
    myDog.animalSound();
  }
}