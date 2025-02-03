package sem4;

import java.util.Scanner;

public class Task3 {

    public abstract static class PaymentMethod {
        public abstract void processPayment(double amount);
    }

    public static class CreditCard extends PaymentMethod {
        private String cardNumber;

        public CreditCard(String cardNumber) {
            this.cardNumber = cardNumber;
        }

        @Override
        public void processPayment(double amount) {
            System.out.println("Processing credit card payment of $" + amount + " using card number: " + cardNumber);
        }
    }

    public static class PayPal extends PaymentMethod {
        private String email;

        public PayPal(String email) {
            this.email = email;
        }

        @Override
        public void processPayment(double amount) {
            System.out.println("Processing PayPal payment of $" + amount + " for account: " + email);
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("Choose a payment method: 1. Credit Card, 2. PayPal");
        int choice = scanner.nextInt();
        scanner.nextLine();

        PaymentMethod paymentMethod;

        if (choice == 1) {
            System.out.print("Enter your credit card number: ");
            String cardNumber = scanner.nextLine();
            paymentMethod = new CreditCard(cardNumber);
        } else if (choice == 2) {
            System.out.print("Enter your PayPal email: ");
            String email = scanner.nextLine();
            paymentMethod = new PayPal(email);
        } else {
            System.out.println("Invalid choice.");
            scanner.close();
            return;
        }
        System.out.print("Enter the payment amount: ");
        double amount = scanner.nextDouble();
        paymentMethod.processPayment(amount);

        scanner.close();
    }
}
