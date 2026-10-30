import java.util.*;

public class Examfactor {
 
//  public static boolean isPriem(int x) {
//      if (x < 2) return false;
//      for (int i = 2; i <= x / i; i++) if (x % i == 0) return false;
//      return true;
//  }
//  
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
         
        while (true) {
            int l = sc.nextInt(), r = sc.nextInt();
            if (l == 0 && r == 0) break;
             
            int cnt = 0;
            for (int i = l; i <= r; i++) {
                if ((i & 1) == 0) continue;
                for (int j = 3; j <= i / j; j++) {
                     
                    if (i % j == 0) {
                        System.out.print(i + "=" + j + "*" + i / j + " ");
                        cnt++;
                        break;
                    }
                }
                 
                if (cnt == 5) {
                    System.out.println("");
                    cnt = 0;
                }
            }
            if (cnt > 0) System.out.println("");
        }
    }
 
}