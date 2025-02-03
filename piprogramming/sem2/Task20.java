package sem2;

import java.util.Scanner;

public class Task20 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String figureType = sc.nextLine();
        double area = 0;

        switch (figureType) {
            case "square":
                double side = sc.nextDouble();
                area = side * side;
                break;

            case "rectangle":
                double length = sc.nextDouble();
                double width = sc.nextDouble();
                area = length * width;
                break;

            case "circle":
                double radius = sc.nextDouble();
                area = Math.PI * radius * radius;
                break;

            case "triangle":
                double base = sc.nextDouble();
                double height = sc.nextDouble();
                area = (base * height) / 2;
                break;

            default:
                System.out.println("Invalid figure type");
                sc.close();
                return;
        }

        System.out.printf("%.3f\n", area);
        sc.close();
    }
}
