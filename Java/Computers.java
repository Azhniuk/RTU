//Task1-13-02-23

public class Computers {
    int ram = 16, ssd = 100, cpu = 2;
    public static void main(String[] args) {
        Computers comp1 = new Computers();
        Computers comp2 = new Computers();
        comp2.ssd = comp2.ssd *2;
        System.out.println("Total: "+comp1.ssd+comp2.ssd);
        
      }
  }