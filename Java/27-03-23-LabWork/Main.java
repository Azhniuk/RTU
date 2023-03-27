
/// Azhniuk Sofiia Variant 1 id: 221ADB207
import java.util.Scanner;
import java.lang.Math;


class Triangle {
  int a = 1, b, c;
  public void askNumber(){
    System.out.println("Enter side");
     }
  public int perimeter(int a, int b, int c) {
    return a+b+c;
  }
  public double area(int a, int b, int c) {
    return 0.0;
  }
}



class Dog extends Triangle {
  public int perimeter(int a, int b, int c) {
    return a + b + c;
    

  }
  public double area(int a, int b, int c) {
    double area, half;
    half = (a + b + c)/2;
    area = Math.sqrt(half* (half - a)*(half - b)*(half - c));
    return area;
  }
}

class Main {
  public static void main(String[] args) {
    int p;
    double area;
    Triangle triangle = new Triangle();  // Create a Pig object
    Triangle myDog = new Dog();  // Create a Dog object
    Scanner scan = new Scanner(System.in);  
    triangle.askNumber();
    triangle.a  = scan.nextInt(); 
    triangle.b = scan.nextInt(); 
    triangle.c = scan.nextInt(); 
    scan.close();
    
    p = myDog.perimeter(triangle.a, triangle.b,triangle.c);
    System.out.println("Perimeter is: "+p);
    area = myDog.area(triangle.a, triangle.b,triangle.c);
    System.out.println("Area is: "+ area);

  }
}