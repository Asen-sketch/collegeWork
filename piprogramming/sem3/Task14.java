package sem3;

import java.util.Arrays;

public class Task14 {
    public static void main (String args[]) {
        int[] arr = {1, 2, 3, 4, 5};
        int[] rotated = new int[arr.length];
        for (int i = 0; i < arr.length; i++) rotated[(i + 2) % arr.length] = arr[i];
        System.out.println(Arrays.toString(rotated));
    }
}
