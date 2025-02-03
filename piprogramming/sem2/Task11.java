package sem2;

import java.util.Scanner;

public class Task11 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int min = Integer.MAX_VALUE;
        int max = Integer.MIN_VALUE;
        for (int i = 0; i < n; i++) {
            int num = sc.nextInt();
            if (num < min) min = num;
            if (num > max) max = num;
        }
        System.out.println("Min: " + min);
        System.out.println("Max: " + max);
        sc.close();
    }
}

