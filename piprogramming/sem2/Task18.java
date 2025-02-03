package sem2;

import java.util.Scanner;

public class Task18 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int result = factorial(n) * factorial(k) / factorial(n - k);
        System.out.println(result);
        sc.close();
    }

    public static int factorial(int x) {
        int fact = 1;
        for (int i = 1; i <= x; i++) {
            fact *= i;
        }
        return fact;
    }
}

