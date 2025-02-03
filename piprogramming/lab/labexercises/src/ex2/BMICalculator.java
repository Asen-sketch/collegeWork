package ex2;

import java.util.Scanner;

public class BMICalculator {
    private static void printIntroduction() {
        System.out.println("This program is designed to calculate your BMI.");
        System.out.println("=====================================================");
    }

    private static float bmiFor(float height, float weight) {
        return weight/(height*height);
    }

    private static float getBMI(Scanner scan) {
        float heightI, weightP, heightCm, weightKg;

        System.out.print("Enter your height (in inches): ");
        heightI = scan.nextFloat();

        System.out.print("Enter your weight (in pounds): ");
        weightP = scan.nextFloat();

        heightCm = (float) (heightI / 0.3937);
        weightKg = (float) (weightP / 2.2046);

        float heightM = heightCm / 100;

        return bmiFor(heightM, weightKg);
    }

    private static String getStatus(float BMI) {
        if (BMI < 18.5) {
            return "underweight";
        } else if (BMI <= 25) {
            return "normal";
        } else if (BMI <= 30) {
            return "overweight";
        } else if (BMI > 30) {
            return "obese";
        } else {
            System.out.println("invalid");
            return null;
        }
    }

    private static void reportResults(int id, float BMI, String status) {
        System.out.println("User " + id + " has BMI index " + Math.round(BMI) + " (" + status + ").");
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        printIntroduction();
        float BMI = getBMI(scanner);
        String status = getStatus(BMI);
        reportResults(1, BMI, status);
    }
}
