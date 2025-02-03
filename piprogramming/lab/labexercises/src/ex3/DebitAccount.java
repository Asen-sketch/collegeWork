package ex3;

class DebitAccount extends BankAccount {
    public DebitAccount(double sum, double interestRate) {
        super(sum, interestRate);
    }

    @Override
    public double pay() {
        return sum * (interestRate / 100);
    }
}

