package word1;

import java.util.Scanner;

public class Aquarium {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int length = scanner.nextInt();
        int width = scanner.nextInt();
        int height = scanner.nextInt();
        double percent = scanner.nextDouble();

        double volume = length * width * height;
        double liters = volume * 0.001;
        double neededLiters = liters * (1 - percent / 100);
        System.out.println(neededLiters);
    }
}
