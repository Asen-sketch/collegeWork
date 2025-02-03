package word1;

import java.util.Scanner;

public class Fruit {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double strawberryPrice = scanner.nextDouble();
        double bananasKg = scanner.nextDouble();
        double orangesKg = scanner.nextDouble();
        double raspberriesKg = scanner.nextDouble();
        double strawberriesKg = scanner.nextDouble();

        double raspberriesPrice = strawberryPrice / 2;
        double orangesPrice = raspberriesPrice * 0.6;
        double bananasPrice = raspberriesPrice * 0.2;

        double total = (strawberriesKg * strawberryPrice) + (bananasKg * bananasPrice) +
                (orangesKg * orangesPrice) + (raspberriesKg * raspberriesPrice);

        System.out.printf("%.2f", total);
    }
}
