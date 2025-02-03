package sem3;

import java.util.Arrays;

public class Task11 {
    public static void main (String args[]) {
        int[] arr = {1, 5, 6, 2, 12};
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i] > arr[j]) {
                    int temp = arr[i];
                    arr[i] = arr[j];
                    arr[j] = temp;
                }
            }
        }
        System.out.println(Arrays.toString(arr));
    }
}
