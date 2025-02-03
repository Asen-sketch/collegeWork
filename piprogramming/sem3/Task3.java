package sem3;

public class Task3 {
    public static void main (String args[]) {
        int[] arr = {1, 2, 3};
        System.out.println(findMax(arr));
    }

    public static int findMax(int[] arr) {
        int max = arr[0];
        for (int n : arr) if (n > max) max = n;
        return max;
    }
}
