package sem3;

public class Task13 {
    public static void main (String args[]) {
        int[] arr = {1, 2, 3, 2, 1};
        boolean isPalindrome = true;
        for (int i = 0; i < arr.length / 2; i++) {
            if (arr[i] != arr[arr.length - i - 1]) {
                isPalindrome = false;
                break;
            }
        }
        System.out.println("is pal: " + isPalindrome);
    }
}
