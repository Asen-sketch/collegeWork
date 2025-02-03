package word1;

import java.util.Scanner;

public class Campaign {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int days = scanner.nextInt();
        int chefs = scanner.nextInt();
        int cakes = scanner.nextInt();
        int waffles = scanner.nextInt();
        int pancakes = scanner.nextInt();

        double total = days * chefs * ((cakes * 45) + (waffles * 5.8) + (pancakes * 3.2));
        double result = total * 7 / 8;
        System.out.println(result);
    }
}
