package word1;

import java.util.Scanner;

public class InchtoCm {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double inches = scanner.nextDouble();
        double cm = inches * 2.54;
        System.out.println(cm);
    }
}
