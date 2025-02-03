package sem2;

import java.util.Scanner;

public class Task13 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (true) {
            String input = sc.next();
            if (input.equals("Stop")) break;
            System.out.println(input);
        }
        sc.close();
    }
}

