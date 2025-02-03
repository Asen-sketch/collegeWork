package sem2;

import java.util.Scanner;

public class Task4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String day = sc.next();
        if (day.equals("Saturday") || day.equals("Sunday")) {
            System.out.println("Weekend");
        } else if (day.equals("Monday") || day.equals("Tuesday") || day.equals("Wednesday") || day.equals("Thursday") || day.equals("Friday")) {
            System.out.println("Working day");
        } else {
            System.out.println("Error");
        }
        sc.close();
    }
}

