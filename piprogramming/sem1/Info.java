package sem1;

import java.util.Scanner;

public class Info {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter your first name: ");
        String firstName = scanner.nextLine();

        System.out.print("Enter your last name: ");
        String lastName = scanner.nextLine();

        System.out.print("Enter your age: ");
        int age = scanner.nextInt();
        scanner.nextLine();

        System.out.print("Enter your city: ");
        String city = scanner.nextLine();

        System.out.println("You are " + firstName + " " + lastName +
                ", a " + age + "-years old person from " + city + ".");
    }
}
