import java.util.Scanner; 

public class Ex2 {

    public static void main(String[] args){


        int i = 1;
        Scanner scan = new Scanner(System.in);

        Scanner scan1 = new Scanner(System.in);

    do{
        
    String line = scan.nextLine();
    count(line);
    spaces(line); 


    i  = scan.nextInt();
    


        }while(i==1);
    scan.close();
    scan1.close();

    }

  
    public static void count(String line){
        System.out.println(line.length());
    return;
    }

    public static void spaces(String line){
        int spaceCount = 0;
        for (char c : line.toCharArray()) {
            if (c == ' ') {
                spaceCount++;
            }
        }

        System.out.println(spaceCount);
   // assertThat(spaceCount).isEqualTo(EXPECTED_COUNT);
    }
    

      
}



