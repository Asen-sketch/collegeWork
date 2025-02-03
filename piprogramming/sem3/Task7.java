package sem3;

public class Task7 {
    public static void main (String args[]) {
        int[] nums = {-1, -2, 0, 1, 2, 3};
        int pos = 0, neg = 0;
        for (int n : nums) if (n > 0) pos++; else if (n < 0) neg++;
        System.out.println("pos: " + pos + ", neg: " + neg);
    }
}
