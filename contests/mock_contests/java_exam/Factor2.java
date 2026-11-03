import java.util.*;

public class Factor2 {

    public static int[] prime = new int[32];
    public static Scanner sc = new Scanner(System.in);
    public static StringBuilder ans = new StringBuilder();

    public static void countFactor(int n) {
        
        int cnt = 0, p = 0, s = n;

        for (int i = 2; i <= n / i && (p = 0) == 0; i++)
            if (n % i == 0) for (prime[cnt++] = i; n % i == 0; p++, n /= i) ;
        if (n > 1 && ++p > 0) prime[cnt++] = n;

        ans.append(s + "含");
        for (int i = 0; i < cnt; i++) ans.append(prime[i] + ",");
        ans.append("数量" + cnt + (cnt == 1 && p == 2 ? ",质数平方数" : "") + "\n");
    }
    public static void main(String[] s) throws Exception {
        int n; while ((n = sc.nextInt()) != -1) countFactor(n);
        System.out.print(ans);
    }
}