package sem3;

public class Task12 {
    public static void main (String args[]) {
        String[] arr = {"test", "test", "yeah"};
        System.out.println(hasDuplicates(arr));
    }

    public static boolean hasDuplicates(String[] arr) {
        for (int i = 0; i < arr.length; i++) {
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[i].equals(arr[j])) {
                    return true; // Duplicate found
                }
            }
        }
        return false; // No duplicates found
    }
}
