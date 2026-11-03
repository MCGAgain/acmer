//package Atcode;

import java.util.*;
import java.io.*;

public class ABC476D {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static StreamTokenizer in = new StreamTokenizer(br);
    static PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

    static long nextInt() throws Exception{
        in.nextToken(); return (long) in.nval;
    }

    static int bound(long[] arr, int l, int r, long x) {
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (arr[mid] <= x) l = mid;
            else r = mid - 1;
        }

        return l;
    }

    public static void main(String[] s) throws Exception{
        long n = nextInt(), m = nextInt(), k = nextInt(), x = nextInt(), y = nextInt();
        long[] a = new long[(int)n + 10], b = new long[(int)m + 10];

        for (int i = 1; i <= n; i++) a[i] = nextInt();
        for (int i = 1; i <= m; i++) b[i] = nextInt();

        Arrays.sort(a, 1, (int)n + 1);
        Arrays.sort(b, 1, (int)m + 1);

        for (int i = 1; i <= n; i++) a[i] += a[i - 1];

        int maxKind = -1;

        for (int i = 0; i <= m; i++) {
            long cost = (b[i] + k - 1) / k;
            if (cost > y) break;
            y -= cost;
            x += cost * k - b[i];
            maxKind = Math.max(maxKind, i + bound(a, 0, (int)n, x + y * k));
        }

        out.println(maxKind);
        out.flush();
    }
}
