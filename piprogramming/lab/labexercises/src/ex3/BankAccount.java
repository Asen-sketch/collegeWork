package ex3;

abstract class BankAccount implements Payable {
    protected double sum;
    protected double interestRate;

    public BankAccount(double sum, double interestRate) {
        this.sum = sum;
        this.interestRate = interestRate;
    }

    public abstract double pay();
}
