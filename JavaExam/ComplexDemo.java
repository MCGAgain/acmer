

import java.util.*;


public class ComplexDemo {
    public static void main(String[] s) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        while (n-- > 0) {
            int op = sc.nextInt();
            double r1 = sc.nextInt();
            double i1 = sc.nextInt();
            double r2 = sc.nextInt();
            double i2 = sc.nextInt();

            Complex c1 = new Complex(r1, i1);
            Complex c2 = new Complex(r2, i2);
            Complex ans = null;

            switch (op) {
                case 0: ans = c1.complexAdd(c2); break;
                case 1: ans = c1.complexSub(c2); break;
                case 2: ans = c1.complexMuti(c2); break;
                case 3: ans = c1.complexDiv(c2); break;
            }

            System.out.println(ans);
        }
    }
}
