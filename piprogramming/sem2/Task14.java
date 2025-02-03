package sem2;

import java.util.Scanner;

public class Task14 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n;
        while (true) {
            n = sc.nextInt();
            if (n % 10 == 0) break;
            System.out.println("Error: Enter a number divisible by 10");
        }
        sc.close();
    }
}

