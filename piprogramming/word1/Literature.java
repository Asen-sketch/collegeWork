package word1;

import java.util.Scanner;

public class Literature {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int pages = scanner.nextInt();
        double pagesPerHour = scanner.nextDouble();
        int days = scanner.nextInt();
        int hoursPerDay = (int) (pages / pagesPerHour / days);
        System.out.println(hoursPerDay);
    }
}
