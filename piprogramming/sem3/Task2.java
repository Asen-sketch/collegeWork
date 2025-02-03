package sem3;

import java.util.Scanner;

public class Task2 {
    public static void main (String args[]) {
        Scanner sc = new Scanner(System.in);
        int[] nums = new int[5];
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            nums[i] = sc.nextInt();
            sum += nums[i];
        }
        System.out.println("avg: " + (sum / 5.0));
    }
}
