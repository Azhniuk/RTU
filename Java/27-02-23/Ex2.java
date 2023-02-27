import java.util.Scanner; 

public class Ex2 {

    public static void main(String[] args){

    Scanner scan = new Scanner(System.in);
    String line = scan.nextLine();
    count(line);
    spaces(line); 
    scan.close();
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



