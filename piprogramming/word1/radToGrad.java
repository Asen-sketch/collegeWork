package word1;

import java.util.Scanner;

public class radToGrad {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double radians = scanner.nextDouble();
        double degrees = Math.round(radians * 180 / Math.PI);
        System.out.println(degrees);
    }
}
