package sem3;

import java.util.Arrays;
import java.util.Comparator;

public class Task5 {
    public static void main (String args[]) {
        String[] strings = {"test", "testlong", "testlonger"};
        Arrays.sort(strings, Comparator.comparingInt(String::length));
        System.out.println(Arrays.toString(strings));
    }
}
