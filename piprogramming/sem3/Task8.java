package sem3;

public class Task8 {
    public static void main (String args[]) {
        int[] arr1 = {1, 2, 3};
        int[] arr2 = {3, 4, 5};
        for (int n : arr1) for (int m : arr2) if (n == m) System.out.println(n);
    }
}
