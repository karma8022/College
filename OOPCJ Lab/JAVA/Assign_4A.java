package JAVA;
import java.util.*;
public class Assign_4A{
    public static void main(String[]args){
        Scanner sc =new Scanner(System.in);
        int n1,n2,c=0;
        try{
            System.out.println("Enter n1");
            n1=sc.nextInt();
            System.out.println("Enter n2");
            n2=sc.nextInt();
            sc.close();
            if(n2==0){
                throw new ArithmeticException("Denominator is equal to 0");
            }
            else{
                c++;
            }
            System.out.println(n1/n2);
            
        }
        finally{
            if(c==1){
                System.out.print("Output Printed");
            }
            else{
                System.out.print("Error in numbers entered");
            }
        }
        
    } 
   
}


