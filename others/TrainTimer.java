import java.util.Scanner;

class MyTime {
    private int day,hour,minute;
    public MyTime(){}
    public MyTime(int hour, int minute){
        this(0, hour, minute);
    }
    public MyTime(int day, int hour, int minute) {
        this.day = day; this.hour = hour;
        if (minute < 60) this.minute = minute;
    }
    //计算两个时间（自身和参数）的和
    public MyTime timeAdd(MyTime s) {
        MyTime r = new MyTime();
        int m = this.minute + s.minute;
        int h = this.hour + s.hour + m / 60;
        r.minute = m % 60;
        r.hour = h % 24;
        r.day = this.day + s.day + h / 24;
        return r;
    }
    //比较两个时间（自身和参数）是否相同
    public boolean equals(MyTime s){
        return (this.minute == s.minute) && (this.hour == s.hour) && (this.day == s.day);
    }
    //按“13:05”或“+1天06:25”两种格式转化时间
    public String toString(){
        String out;
        if(this.day != 0){
            if(this.hour<10) {
                if(this.minute<10) out = String.format("+%d天0%d:0%d",this.day,this.hour,this.minute);
                else out = String.format("+%d天0%d:%d",this.day,this.hour,this.minute);
            }
            else {
                if(this.minute<10) out = String.format("+%d天%d:0%d",this.day,this.hour,this.minute);
                else out = String.format("+%d天%d:%d",this.day,this.hour,this.minute);
            }
        }
        else{
            if(this.hour<10) {
                if(this.minute<10) out =String.format("0%d:0%d",this.hour,this.minute);
                else out =String.format("0%d:%d",this.hour,this.minute);
            }
            else {
                if(this.minute<10) out =String.format("%d:0%d",this.hour,this.minute);
                else out =String.format("%d:%d",this.hour,this.minute);
            }
        }
        return out;
    }
    //按“11小时45分钟”中文形式转化时间
    public String toCNString(){
        String out;
        if(this.day != 0) out =String.format("+%d天%d小时%d分钟",this.day,this.hour,this.minute);
        else out =String.format("%d小时%d分钟",this.hour,this.minute);
        return out;
    }
}

public class TrainTimer {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true){
            int hour = sc.nextInt(),minute = sc.nextInt();
            if((hour == -1)&&(minute == -1)) break;
            MyTime t_act = new MyTime(hour,minute);
            hour = sc.nextInt();
            minute = sc.nextInt();
            MyTime t_run = new MyTime(hour,minute);
            int day = sc.nextInt();
            hour = sc.nextInt();
            minute = sc.nextInt();
            MyTime t_end = new MyTime(day,hour,minute);
            //计算到达时间
            MyTime t_count = t_act.timeAdd(t_run);
            String same="不一致";
            if(t_count.equals(t_end)) same ="一致";
            System.out.println(t_act.toString()+" + "+t_run.toCNString()+" -> "+
                    t_count.toString()+" == "+t_end.toString()+" ? "+same);
        }
    }
}
