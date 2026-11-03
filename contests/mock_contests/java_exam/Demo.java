
import java.util.*;

class MyTime {
    private int day, hour, minute;
    
    MyTime() {}

    MyTime(int hour, int minute) {
        this(0, hour, minute);
    }

    MyTime(int day, int hour, int minute) {
        this.day = day;
        this.hour = hour;
        this.minute = minute >= 0 && minute < 60 ? minute : 0;
    }

    public MyTime timeAdd(MyTime o) {
        MyTime temp = new MyTime();

        int additionalHour = (o.minute + this.minute) / 60;
        temp.minute = (this.minute + o.minute) % 60;
        int additionalDay = (o.hour + this.hour + additionalHour) / 24;
        temp.hour = (o.hour + this.hour + additionalHour) % 24;
        temp.day = o.day + this.day + additionalDay;
        return temp;
    }

    public boolean equals(MyTime o) {
        return this.day == o.day && this.hour == o.hour && this.minute == o.minute;
    }

    public String toString() {
        String s = String.format("%02d:%02d", hour, minute);
        return this.day == 0 ? s : "+" + this.day + "天" + s;
    }

    public String toCNString() {
        return this.hour + "小时" + this.minute + "分钟";
    } 

}

public class Demo {

    public static void main(String[] s) {
        Scanner sc = new Scanner(System.in);

        while (true) {
            int beginHour = sc.nextInt(), beginMinute = sc.nextInt();
            if (beginHour == -1 && beginMinute == -1) break;
            int runHour = sc.nextInt(), runMinute = sc.nextInt();
            int planDay = sc.nextInt(), planHour = sc.nextInt(), planMinute = sc.nextInt();

            MyTime beginTime = new MyTime(beginHour, beginMinute), runTime = new MyTime(runHour, runMinute), planTime = new MyTime(planDay, planHour, planMinute);
            MyTime countTime = beginTime.timeAdd(runTime);

            System.out.println(beginTime + " + " + runTime.toCNString() + " -> " + countTime + " == " + planTime + " ? " + (planTime.equals(countTime) ? "一致" : "不一致"));
        }
    } 
}