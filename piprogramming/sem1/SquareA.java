package sem1;

import java.util.Scanner;

public class SquareA {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the side length of the square: ");
        double a = scanner.nextDouble();
        double area = a * a;
        System.out.println("Area of the square: " + area);
    }
}
