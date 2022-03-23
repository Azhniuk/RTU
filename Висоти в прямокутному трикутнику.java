import java.util.Scanner;


public class School {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);


		float a = scan.nextInt();
        float b = scan.nextInt();
        float c = scan.nextInt();


        float p = ((a + b + c)/2);

        double ha, hb, hc;


        ha = 2*Math.sqrt(p*(p-a)*(p-b)*(p-c))/a;
        hb = 2*Math.sqrt(p*(p-a)*(p-b)*(p-c))/b;
        hc = 2*Math.sqrt(p*(p-a)*(p-b)*(p-c))/c;

        System.out.printf("%.3f \n", ha);
        System.out.printf("%.3f \n", hb);
        System.out.printf("%.3f \n", hc);
        
        

       


    }

    
}
