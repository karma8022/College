import java.util.*;
import java.lang.*;

class logic extends Thread implements Runnable{
    int a,b,choice;

    @Override
    public synchronized void start(){
        System.out.println("Thread has been started");
        super.start();
    }

    @Override
    public void run(){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter your choice:");
        System.out.println("1 Add:");
        System.out.println("2 Sub");
        System.out.println("3 Mul");
        System.out.println("4 Div");
        choice =sc.nextInt();
        System.out.println("Enter a");
        a = sc.nextInt();
        System.out.println("Enter b");
        b = sc.nextInt();
        switch(choice){
            case 1:
                System.out.println(a+b);
                break;
            case 2:
                System.out.println(a-b);
                break;
            case 3:
                System.out.println(a*b);
                break;
            case 4:
                try{
                    System.out.println(a/b);
                }
                catch (ArithmeticException E){
                    System.out.println("Bruh cant divide by zero");
                }
                break;
            default:
                break;
        }
        
    }

}

public class Calculator{
    public static void main(String[]args){
        logic l = new logic();
    }
}