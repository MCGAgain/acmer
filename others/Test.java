import java.util.*;
import java.io.*;
public class Test {
    public static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static StreamTokenizer in = new StreamTokenizer(br);
    public static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
 
    public static void factor(int n) {
        int sum = 0, cnt = 0, t = n;
        for (int i = 2; i <= n / i; i++){
            if (n % i == 0) {
                sum += i; cnt++;
                if (i != n / i) {
                    sum += n / i; cnt++;
                }
            }
        }
         
        if (cnt == 0) {
            out.println("Error");
            return ;
        }
         
        out.printf("%d %.2f %s\n",cnt, (double)sum / cnt, (sum / cnt * cnt == sum ? "Integer" : "Float"));
    }
     
    public static void main(String[] args) throws Exception {

        while (true) {
            in.nextToken(); int n = (int) in.nval;
            if (n == -1) break;
            factor(n);
        }
        out.flush();
    }
 
}