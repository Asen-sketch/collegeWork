package sem2;

import java.util.Scanner;

public class Task5 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println((n >= -100 && n <= 100 && n != 0) ? "Yes" : "No");
        sc.close();
    }
}

