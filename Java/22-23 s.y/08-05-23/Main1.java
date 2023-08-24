public class Main1 extends Thread  

{   
    public int main = 0; 
    public void run()  
    {    
        for(int i=1;i<300;i++)  
        { 
            System.out.println("Thread - "+Thread.currentThread().getName() +" - " +i); 
          
            if (main%3==0){
                System.out.println("main - main -"+i);
            }
            main++;
           
            try 
            {  
                Thread.sleep(500);  
            }catch(InterruptedException e)
            {System.out.println(e);}   
          
        }    
    }    
    public static void main(String args[])  
    {   
        
        Main1 thread1=new Main1();    
        Main1 thread2=new Main1();   
        Main1 thread3=new Main1();   
        //Main1 main=new Main1();     
        thread1.start();    
        thread2.start();    
        thread3.start(); 

         
    }    
} 