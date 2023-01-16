package JAVA;
import java.util.*;


class Bank{
    long CID;
    String Cname;
    int balance;
    int moved;   
    int c=0;

void Logic(){
    Scanner sc = new Scanner(System.in);
        try{
            System.out.println("Enter cid:");
            CID = sc.nextLong();
            System.out.println("Enter name:");
            Cname=sc.next();
            System.out.println("Enter ammount to intially deposit:");
            balance=sc.nextInt();
            System.out.println("Enter amount to be withdrawn:");
            moved = sc.nextInt();
            sc.close();
            if(CID<1||CID>20){
                throw new ArithmeticException("CID not in valid range");
            }
            else{
                c++;
            }
            if(balance<1000){
                throw new ArithmeticException("Balance not in valid range:");
            }
            else{
                c++;
            }
            if(moved>balance){
                throw new ArithmeticException("Amount is more than balance");
            }
            else{
                balance = balance-moved;
                c++;
            }
            
        }
        finally{
            if(c==3){
                System.out.println("Transactions have been performed succesfully ");
            }
            else{
                System.out.println("Error in entry");
            }
        }
}



public class Assign_4B{
    public static void main(String[]args){
        
        
    }
}} 


    