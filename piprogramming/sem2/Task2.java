package sem2;

import java.util.Scanner;

public class Task2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        System.out.println(num % 2 == 0 ? "Even" : "Odd");
        sc.close();
    }
}

