import java.util.Scanner;
import java.text.DecimalFormat;
import java.lang.Math;

class Complex {
    private double realPart;
    private double imaginPart;

    public Complex() {
    }

    public Complex(double r, double i) {
        this.realPart = r;
        this.imaginPart = i;
    }

    public double getMod() {
        return Math.sqrt(Math.pow(this.realPart, 2) + Math.pow(this.imaginPart, 2));
    }

    public Complex horiMove(int direction, double len) {
        if (direction == 1) {
            this.realPart += len;
        } else if (direction == -1) {
            this.realPart -= len;
        }
        return this;
    }

    public Complex complexAdd(Complex c) {
        Complex result = new Complex(this.realPart, this.imaginPart);
        result.realPart += c.realPart;
        result.imaginPart += c.imaginPart;
        return result;
    }

    public String toString() {
        DecimalFormat df = new DecimalFormat("#.###");
        String rp = df.format(realPart);
        String ip = df.format(imaginPart);

        String result;
        if (realPart != 0) {
            if (imaginPart == 0) result = rp;
            else if (imaginPart == 1) result = rp + "+" + "i";
            else if (imaginPart == -1) result = rp + "-" + "i";
            else if (imaginPart > 0) result = rp + "+" + ip + "i";
            else result = rp + ip + "i";
             
        }
        else {
            if (imaginPart == 0) result = "0";
            else if (imaginPart == 1) result = "i";
            else if (imaginPart == -1) result = "-i";
            else result = ip + "i";
        }

        String xx;
        if(this.realPart == 0||this.imaginPart == 0) xx = "";
        else if (this.realPart > 0) {
            if (this.imaginPart > 0) {
                xx = "(1象限)";
            } else {
                xx = "(4象限)";
            }
        } else {
            if (this.imaginPart < 0) {
                xx = "(3象限)";
            } else {
                xx = "(2象限)";
            }
        }
        return result+xx;
    }
}
public class DJY {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 0; i < n; i++) {
            double realPart, imaginPart;
            realPart = sc.nextDouble();
            imaginPart = sc.nextDouble();
            Complex c = new Complex(realPart, imaginPart);
            System.out.print(c.toString() + ",");
            System.out.printf("%.3f,",c.getMod());
            int direction;
            double len;
            direction = sc.nextInt();
            len = sc.nextDouble();

            System.out.print(c.horiMove(direction, len).toString());
            System.out.println();
        }
        Complex c1 = new Complex(1.23, 3.14);
        Complex c2 = new Complex(1, 2);
        Complex c3 = new Complex();
        c3 = c1.complexAdd(c2);
        System.out.println("c3=c1+c2=" + c3.toString());
    }
}