package word1;

import java.util.Scanner;

public class Greenhouse {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double area = scanner.nextDouble();
        double price = area * 7.61;
        double discount = price * 0.18;
        double finalPrice = price - discount;
        System.out.printf("The final price is: %.2f lv.%n", finalPrice);
        System.out.printf("The discount is: %.2f lv.", discount);
    }
}
