
import java.util.Scanner;
import java.lang.Integer;

public class Main {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);

        int a1;
        float a, b1, n = scan.nextInt();

        for (Integer b = 1; b <= 10000; b++) {
            b1 = b.floatValue();
            a = (n + (2 * b1)) / 5;
            a1 = Math.round(a);

            if ((a - a1) == 0) {
                System.out.println(a1 + "   DDD " + b);
                break;

            }

            scan.close();
        }
    }

}