import java.util.*;
public class collection{
    public static void main(String[] args){
        int n;
        Scanner sc = new Scanner(System.in);
        ArrayList<String> al = new ArrayList<String>();
        System.out.println("Enter the amount of elements to add");
        n = sc.nextInt();
        for(int i=0;i<n;i++){
            System.out.println("Enter element to add");
            al.add(i,sc.next());
        }
        Iterator it = al.iterator();
        while(it.hasNext()){
            System.out.println(it.next());
        }
    }
}