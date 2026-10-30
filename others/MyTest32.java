public class MyTest32 {

    static int x=10;

    static {

        x+=1;

        System.out.println("1,"+x);

    }

    public static void main(String args[]){ 

        x+=2;

        System.out.println("2,"+x);

    }

    static {

        x+=3;

        System.out.println("3,"+x);

    }

}