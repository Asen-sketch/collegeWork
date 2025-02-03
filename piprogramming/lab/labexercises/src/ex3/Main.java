package ex3;

public class Main {
    public static void main(String[] args) {
        DebitAccount debitAccount = new DebitAccount(1000, 5);
        CreditAccount creditAccount = new CreditAccount(1000, 5, 12);

        System.out.println("Debit Account Interest: " + debitAccount.pay());
        System.out.println("Credit Account Interest: " + creditAccount.pay());
    }
}
