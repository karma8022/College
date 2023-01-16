package JAVA;
import java.util.*;
 class Employee{
    int emp_id,basic_salary;
    String emp_city,emp_name;
    double HRA,DA,gross_salary,sal_hike;
    Scanner sc =new Scanner(System.in);
    void display_salary(){

    }
    void accept_details(){
        System.out.println("Enter Name:");
        emp_name =sc.nextLine();
        System.out.println("Enter ID:");
        emp_id= sc.nextInt();
    } 
    void display_details(){
        System.out.println("Name is :"+emp_name);
        System.out.println("ID is :"+emp_id);
    }  
 }

class Full_Time extends Employee{
    void calculate_salary(){
        System.out.println("Enter basic pay:");
        basic_salary=sc.nextInt();
        DA=0.20*basic_salary;
        HRA=0.15*basic_salary;
        gross_salary=basic_salary+DA+HRA;
        sal_hike=(0.5*gross_salary)+gross_salary;
    }
    void display_salary(){
        accept_details();
        display_details();
        calculate_salary();
        System.out.println("Gross salary is:"+gross_salary);
        System.out.println("Post hike salary is:"+sal_hike);
    }

}


public class Assign_1{
   public static void main(String[]args){
        Full_Time One =new Full_Time();
        One.display_salary();
    }

}

