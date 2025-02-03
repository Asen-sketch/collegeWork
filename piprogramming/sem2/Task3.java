package sem2;

import java.util.Scanner;

public class Task3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int dayNumber = sc.nextInt();
        if (dayNumber < 1 || dayNumber > 7) {
            System.out.println("Error");
        } else {
            String[] days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
            System.out.println(days[dayNumber - 1]);
        }
        sc.close();
    }
}

