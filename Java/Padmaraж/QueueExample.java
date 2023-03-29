import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class QueueExample {
    public static void add(String name, Queue<String> queue, Scanner scan) {
        System.out.println("Your name: ");
        name = scan.next();
        queue.add(name); 
        return;
    }

    public static void delete(Queue<String> queue, Scanner scan) {
        queue.remove(); 
        return;
    }


    

    public static void main(String[] args) {
        Queue<String> queue = new LinkedList<>();

        boolean iscontinue = true;
        Integer result;
        String name = "L";
        Scanner scan = new Scanner(System.in);


        while (iscontinue){
        System.out.println("Do you want to be in queue(press 1) or remove somebody from the queue(press 2)?\nTo end press 0");
        result = scan.nextInt();
        if(result==1){
            add(name, queue, scan);
        }
        else if(result==2 ){
            delete(queue, scan);
        }
        else if(result == 0){
            System.out.println("Good luck");
            iscontinue = false;
        }

        System.out.println("The queue is: "+ queue);  
        result = 5;   
        }
        scan.close();       

    }

}

        

       
    
