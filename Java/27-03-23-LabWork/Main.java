
/// Azhniuk Sofiia Variant 1 id: 221ADB207
//I uploaded the first variant with input from user, but here it reads numbers from the given file. If i understand the assignment correctly.

import java.util.Scanner;
import java.lang.Math;
import java.io.File;  
import java.io.FileNotFoundException;

import java.io.*;
import java.util.*;


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

  public ArrayList<Integer> read(){
    try {
      ArrayList<Integer> nums  = new ArrayList<>();
      File myObj = new File("main.txt");
      Scanner myReader = new Scanner(myObj);
      while (myReader.hasNextLine()) {
        int number = myReader.nextInt();
        nums.add(number);
      }
      myReader.close();
      return nums;
    } catch (FileNotFoundException e) {
      System.out.println("An error occurred.");
      e.printStackTrace();
    }
    return null;
  }
}



class Shape extends Triangle {
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
    Triangle shape = new Shape();  // Create a Dog object
    Scanner scan = new Scanner(System.in);  
    ArrayList<Integer> nums  = triangle.read();
    triangle.askNumber();
    triangle.a  = nums.get(0); 
    triangle.b = nums.get(1); 
    triangle.c = nums.get(2); 
    scan.close();
    
    p = shape.perimeter(triangle.a, triangle.b,triangle.c);
    System.out.println("Perimeter is: "+p);
    area = shape.area(triangle.a, triangle.b,triangle.c);
    System.out.println("Area is: "+ area);

    

  }
}