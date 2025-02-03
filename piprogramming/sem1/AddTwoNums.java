package sem1;

import java.util.Scanner;

public class AddTwoNums {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter first number: ");
        int num1 = scanner.nextInt();
        System.out.print("Enter second number: ");
        int num2 = scanner.nextInt();
        System.out.println("Sum: " + (num1 + num2));
    }
}
