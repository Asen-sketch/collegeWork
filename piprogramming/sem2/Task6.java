package sem2;

import java.util.Scanner;

public class Task6 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        System.out.println((x >= 100 && x <= 200) ? "Valid" : "Invalid");
        sc.close();
    }
}

