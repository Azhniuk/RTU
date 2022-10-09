import java.util.Arrays;
import java.util.Random;
 
public class Sort {
    public static void main(String[] args) {
        int [] mas = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int j, k;
        Random rndm = new Random();
        boolean Sorted = false;


        for (int i = 0; i<=9; i++){
            j= rndm.nextInt(100);
            mas[i]= j;
        }
        System.out.println(Arrays.toString(mas));


        while(!Sorted) {
            Sorted = true;
            for (int i = 0; i < mas.length-1; i++) {
                if(mas[i] > mas[i+1]){
                    Sorted = false;
                    k = mas[i];
                    mas[i] = mas[i+1];
                    mas[i+1] = k;
                }
            }
        }
   
     System.out.println(Arrays.toString(mas));
    }
    
}