package sem2;

import java.util.Scanner;

public class Task19 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        double budget = sc.nextDouble();
        int extrasCount = sc.nextInt();
        double clothingPricePerExtra = sc.nextDouble();

        double decorCost = budget * 0.1;
        double clothingCost = extrasCount * clothingPricePerExtra;

        if (extrasCount > 150) {
            clothingCost *= 0.9;
        }

        double totalCost = decorCost + clothingCost;

        if (totalCost > budget) {
            System.out.println("Not enough money!");
            System.out.printf("Wingard needs %.2f leva more.\n", totalCost - budget);
        } else {
            System.out.println("Action!");
            System.out.printf("Wingard starts filming with %.2f leva left.\n", budget - totalCost);
        }

        sc.close();
    }
}
