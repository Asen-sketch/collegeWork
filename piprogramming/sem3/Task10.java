package sem3;

import java.util.Arrays;

public class Task10 {
    public static void main (String args[]) {
        int[] arr = {1, 2, 3, 4};
        int target = 3;
        int[] result = Arrays.stream(arr).filter(n -> n != target).toArray();
        System.out.println(Arrays.toString(result));
    }
}
