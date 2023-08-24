import java.util.Scanner; 
public class Main {

    public static String encrypt(String line){

        char[] arr = new char[7];

    // Copy character by character into array
    for (int i = 0; i < 7; i++) {
      arr[i] = line.charAt(i);
    }
    
    
    for (int i = 0; i<7; i++){
        arr[i]= arr[i]+1;

        }

        return line;
    }


    
    
    public static void main(String[] args){
        
        Scanner scan = new Scanner(System.in);
        System.out.println("Sentence:");
        String line = scan.nextLine();
        System.out.println("Password:");
        String password = scan.nextLine();

        Settings sg = new Settings();
        String pass1 = sg.getKey();

        if(pass1.equals(password)){
            System.out.println("Ok:");
        }
    
        else{
        System.out.println("Wrong password");
        }
    
    
        scan.close();
    }
    

}
