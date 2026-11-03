
import java.text.DecimalFormat;

public class Complex {
    private double realPart, imaginPart;
    
    //----init----
    public Complex() {}
    public Complex(double r, double i) {
        realPart = r;
        imaginPart = i;
    }

    //----setter----
    void setReal(double r) {
        realPart = r;
    }

    void setImagin(double i) {
        imaginPart = i;
    }

    //----getter----
    double getReal() {
        return realPart;
    }

    double getImagin() {
        return imaginPart;
    }

    //----operation----
    public Complex conjugate() {
        return new Complex(this.realPart, -this.imaginPart);
    }

    public Complex complexAdd(Complex o) {
        return new Complex(this.realPart + o.realPart, this.imaginPart + o.imaginPart);
    }

    public Complex complexSub(Complex o) {
        return new Complex(this.realPart - o.realPart, this.imaginPart - o.imaginPart);
    }

    public Complex complexMuti(Complex o) {
        return new Complex(this.realPart * o.realPart - this.imaginPart * o.imaginPart, this.realPart * o.imaginPart + this.imaginPart * o.realPart);
    }

    public Complex complexDiv(Complex o) {
        Complex conjugateComplex = o.conjugate();
        Complex numerator = this.complexMuti(conjugateComplex);
        Complex denominator = o.complexMuti(conjugateComplex);
        return new Complex(numerator.realPart / denominator.realPart, numerator.imaginPart / denominator.realPart);
    }

    //----reWrite----

    public boolean equal(Complex o) {
        return this.realPart == o.realPart && this.imaginPart == o.imaginPart;
    }

    public String toString() {
        String res = "";

        DecimalFormat df = new DecimalFormat("#.##");
        String rp = df.format(realPart);
        String ip = df.format(imaginPart);

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
