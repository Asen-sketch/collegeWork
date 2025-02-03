package word1;

import java.util.Scanner;

public class USDtoBGN {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        double usd = scanner.nextDouble();
        double bgn = usd * 1.79549;
        System.out.println(bgn);
    }
}
