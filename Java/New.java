import java.util.Scanner;
 
class New
{
   public static void main(String args[])
   {
    int z;
 
    System.out.println("Enter two integers to calculate their sum");
    Scanner scan = new Scanner(System.in);
  	Integer x = scan.nextInt();
  	Integer y = scan.nextInt();
  	z = x + y;
    scan.close();
 
 	System.out.println("Sum of the integers = " + z);
   }
}
