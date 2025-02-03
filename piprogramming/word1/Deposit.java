package word1;

import java.util.Scanner;

public class Deposit {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double depositAmount = scanner.nextDouble();
        int months = scanner.nextInt();
        double annualInterest = scanner.nextDouble();
        double totalAmount = depositAmount + months * ((depositAmount * annualInterest / 100) / 12);
        System.out.println(totalAmount);
    }
}
