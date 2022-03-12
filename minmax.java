import java.util.Arrays;
import java.util.Random;
 
public class minmax {
    public static void main(String[] args) {
        int [] mas = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        int j;
        Random rndm = new Random();


        for (int i = 0; i<=9; i++){
            j= rndm.nextInt(100);
            mas[i]= j;
        }
        System.out.println(Arrays.toString(mas));
        int max_num = mas[0], min_num = mas[0];

        for (int i= 0; i<= mas.length-1; i++){
            if (max_num < mas[i]){
                max_num = mas[i];                
            }
            else if (min_num > mas[i]){
                min_num = mas[i];                
            }
        }

   
     System.out.println("The lardest number:"+max_num);
     System.out.println("The smallest number:"+min_num);
    }
    
}