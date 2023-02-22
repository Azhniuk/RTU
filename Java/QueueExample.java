import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;


public class QueueExample {
    public static void add(Queue<String> queue) {
        Scanner scan = new Scanner(System.in);

        System.out.println("Your name: ");
        String name = scan.nextLine();
        queue.add(name);
        scan.close();

        return;
    }


    public static void main(String[] args) {
        Queue<String> queue = new LinkedList<>();
        Scanner scan = new Scanner(System.in);

        System.out.println("Do you want to be in queue(press 1) or remove somebody from the queue(press 2)?");
        Integer result = scan.nextInt();
        if(result == 1){
            add(queue);
            System.out.println("The queue is: "+ queue);
            
           
            //queue.add(name);
            
        }
        else if(result == 2){
        }

       
        /*
        queue.add(2);
        queue.add(3);
        queue.add(4);
        queue.add(5);

        // Dequeue elements from the queue
        int firstElement = queue.remove();
        System.out.println("Removed element: " + firstElement);

        // Print the remaining elements in the queue
        

        // Get the size of the queue
        System.out.println("Queue size: " + queue.size());

        // Check if the queue is empty
        System.out.println("Is queue empty? " + queue.isEmpty());
        */
        scan.close();

    }
}
