import java.util.Scanner;
 
class Main
{
   public static void main(String args[])
   {
    int x, y, z;
 
    System.out.println("Enter two integers to calculate their sum");
    Scanner scan = new Scanner(System.in);
  	x = scan.nextInt();
  	y = scan.nextInt();
  	z = x + y;
    scan.close();
 
 	System.out.println("Sum of the integers = " + z);
   }
}
