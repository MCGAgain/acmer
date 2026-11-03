
import java.util.*;
import java.io.*;

public class P1908 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer in = new StreamTokenizer(br);
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    static final int N = (int) 5e5 + 10;

    static int[] a = new int[N], Tree = new int[N];
    static int n;

    static int lowbit(int i) {
        return i & -i;
    }

    static void add(int x, int k) {
        for (int i = x; i <= n; i += lowbit(i)) Tree[i] += k;
    }

    static int sum(int x) {
        int ans = 0;
        for (int i = x; i > 0; i -= lowbit(i)) ans += Tree[i];
        return ans;
    }
    static int cnt = 1;
    static int[] unique(int[] arr) {
        int[] b = new int[n + 10];
    
        for (int i = 1; i <= n; i++) {
            if (arr[i] != b[cnt]) b[cnt++] = arr[i];
        }
        return b;
    }

    static int lowerBound(int[] a, int l, int r, int x) {
        while (l < r) {
            int mid = (l + r) >> 1;
            if (a[mid] >= x) r = mid;
            else l = mid + 1;
        }

        return l;
    }

    public static void main(String[] s) throws Exception{
        in.nextToken(); n = (int) in.nval;
        for (int i = 1; i <= n; i++) {
            in.nextToken(); a[i] = (int) in.nval;
        }

        int[] help = new int[n + 10];
        System.arraycopy(a, 1, help, 1, n);
        Arrays.sort(help, 1, n + 1);
        int[] b = unique(help);

        for (int i = 1; i <= n; i++) {
            a[i] = lowerBound(b, 1, cnt - 1, a[i]);
        }

        long ans = 0;
        for (int i = n; i >= 1; i--) {
            ans += sum(a[i] - 1);
            add(a[i], 1);
        }

        

        out.println(ans);
        out.flush();

    }
}
