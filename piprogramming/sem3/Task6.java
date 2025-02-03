package sem3;

public class Task6 {
    public static void main (String args[]) {
        int[] arr = {1, 2, 3};
        System.out.println(search(arr, 1));
    }

    public static int search(int[] arr, int target) {
        for (int i = 0; i < arr.length; i++) if (arr[i] == target) return i+1;
        return -1;
    }
}
