
import java.util.*;
import java.text.DecimalFormat;

class Complex {
    private double realPart, imaginPart;
    
    //----init----
    public Complex() {}
    public Complex(double r, double i) {
        realPart = r;
        imaginPart = i;
    }

    //----operation----
    public Complex complexAdd(Complex o) {
        return new Complex(this.realPart + o.realPart, this.imaginPart + o.imaginPart);
    }

    public Complex complexSub(Complex o) {
        return new Complex(this.realPart - o.realPart, this.imaginPart - o.imaginPart);
    }

    public Complex complexMulti(Complex o) {
        return new Complex(this.realPart * o.realPart - this.imaginPart * o.imaginPart, this.realPart * o.imaginPart + this.imaginPart * o.realPart);
    }

    public Complex complexDiv(Complex o) {
        Complex conjugateComplex = new Complex(o.realPart, -o.imaginPart);
        Complex numerator = this.complexMulti(conjugateComplex);
        Complex denominator = o.complexMulti(conjugateComplex);
        return new Complex(numerator.realPart / denominator.realPart, numerator.imaginPart / denominator.realPart);
    }

    //----reWrite----
    public String toString() {
        String res = "";

        DecimalFormat df = new DecimalFormat("#.##");
        String rp = df.format(realPart + 1e-7);
        String ip = df.format(imaginPart + 1e-7);

        if (realPart != 0) {
            if (imaginPart == 0) res = rp;
            else if (imaginPart == 1) res = rp + "+" + "i";
            else if (imaginPart == -1) res = rp + "-" + "i";
            else if (imaginPart > 0) res = rp + "+" + ip + "i";
            else res = rp + ip + "i";
             
        }
        else {
            if (imaginPart == 0) res = "0";
            else if (imaginPart == 1) res = "i";
            else if (imaginPart == -1) res = "-i";
            else res = ip + "i";
        }

        return res;
    }

}


public class ComplexDemo {
    public static void main(String[] s) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        while (n-- > 0) {
            Complex c1 = new Complex(sc.nextDouble(), sc.nextDouble()), c2 = new Complex(sc.nextDouble(), sc.nextDouble());
            System.out.printf("c1=%s\nc2=%s\nc3=c1+c2=%s\nc3=c1-c2=%s\nc3=c1*c2=%s\nc3=c1/c2=%s\n", c1, c2, c1.complexAdd(c2), c1.complexSub(c2), c1.complexMulti(c2), c1.complexDiv(c2));            
        }
    }
}
