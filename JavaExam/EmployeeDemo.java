import java.util.*;
import java.text.DecimalFormat;

class Employee {
    private String name;
    public Employee (String name) {
        this.name = name;
    }

    public int getSalary() {
        return 0;
    }

    public String getName() {
        return name;
    }

    public String toString() {
        return getName() + ":" + getSalary();
    }
}

class Manager extends Employee {
    private int monthSalary;
    public Manager (String name, int monthSalary) {
        super(name);
        this.monthSalary = monthSalary;
    }

    public int getSalary() {
        return monthSalary;
    }
}

class Salesman extends Employee {
    private int baseSalary, commission;

    public Salesman (String name, int baseSalary, int commission) {
        super(name);
        this.baseSalary = baseSalary;
        this.commission = commission;
    }

    public int getSalary() {
        return baseSalary + commission;
    }
}

class Worker extends Employee {
    private int day, salaryByDay;

    public Worker (String name, int day, int salaryByDay) {
        super(name);
        this.day = day;
        this.salaryByDay = salaryByDay;
    }

    public int getSalary() {
        return day * salaryByDay;
    }
}

public class EmployeeDemo {
    
    public static void main(String []s) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        Employee[] arr = new Employee[n];

        for (int i = 0; i < n; i++) {
            switch (i % 3) {
                case 0:
                    arr[i] = new Manager(sc.next(), sc.nextInt());
                    break;
                case 1:
                    arr[i] = new Salesman(sc.next(), sc.nextInt(), sc.nextInt());
                    break;
                default:
                    arr[i] = new Worker(sc.next(), sc.nextInt(), sc.nextInt());
                    break;
            }
        }
        int sum = 0;
        for (int i = 0; i < n; sum += arr[i].getSalary(), i++) System.out.println(arr[i]);
        System.out.println("total:" + sum);
    }
}
