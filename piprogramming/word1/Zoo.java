package word1;

import java.util.Scanner;

public class Zoo {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int dogs = scanner.nextInt();
        int otherAnimals = scanner.nextInt();
        double total = dogs * 2.50 + otherAnimals * 4.00;
        System.out.printf("%.2f lv.", total);
    }
}
