package sem2;

import java.util.Scanner;

public class Task10 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            if (i % 5 == 0 && i % 7 == 0) {
                System.out.println(i);
            }
        }
        sc.close();
    }
}

