
import java.util.Scanner;
public class Test{
   public static void main(String args[ ]){
      System.out.println("你好，请圉國一个整圌：");
      Scanner sc=new Scanner(System.in);
      int num=sc.nextInt();
      System.out.println("你圉國的整圌是："+num);
      int sum=0;
      for(int i=1;i<num + 1;i++){
          sum+=i;      
      }
      System.out.println("从1累加到"+num+"的总和是"+sum);
      sc.close();
   } //end of main method
} //end of class 