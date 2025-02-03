package word1;

import java.util.Scanner;

public class SquareArea {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int side = scanner.nextInt();
        int area = side * side;
        System.out.println(area);
    }
}
