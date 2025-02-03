package sem3;

public class Task15 {
    public static void main (String args[]) {
        int[] arr = {1, 2, 3, 4, 5};
        int max1 = Integer.MIN_VALUE, max2 = Integer.MIN_VALUE;
        for (int n : arr) {
            if (n > max1) {
                max2 = max1;
                max1 = n;
            } else if (n > max2 && n != max1) max2 = n;
        }
        System.out.println("second max: " + max2);
    }
}
