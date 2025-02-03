package sem2;

import java.util.Scanner;

public class Task15 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int hours = sc.nextInt();
        int minutes = sc.nextInt();
        minutes += 15;
        hours = (hours + minutes / 60) % 24;
        minutes %= 60;
        System.out.printf("%02d:%02d\n", hours, minutes);
        sc.close();
    }
}

