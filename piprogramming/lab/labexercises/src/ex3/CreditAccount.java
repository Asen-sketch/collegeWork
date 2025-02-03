package ex3;

class CreditAccount extends BankAccount {
    private int months;

    public CreditAccount(double sum, double interestRate, int months) {
        super(sum, interestRate);
        this.months = months;
    }

    @Override
    public double pay() {
        return sum * Math.pow(1 + (interestRate / 100), months) - sum;
    }
}
