package sem1;

import java.util.Scanner;

public class InchConverter {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter inches: ");
        double inches = scanner.nextDouble();
        double centimeters = inches * 2.54;
        System.out.println(inches + " inches is " + centimeters + " centimeters");
    }
}
