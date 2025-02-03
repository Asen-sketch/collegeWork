package ex2;

public class CompanyET extends Company {
    private String ownerName;
    private double initialCapital;
    private double currentCapital;

    public CompanyET(String name, String creationDate, String bulstat, String ownerName, double initialCapital, double currentCapital) {
        super(name, creationDate, bulstat);
        this.ownerName = ownerName;
        this.initialCapital = initialCapital;
        this.currentCapital = currentCapital;
    }

    public String getOwnerName() {
        return ownerName;
    }

    public void setOwnerName(String ownerName) {
        this.ownerName = ownerName;
    }

    public double getInitialCapital() {
        return initialCapital;
    }

    public void setInitialCapital(double initialCapital) {
        this.initialCapital = initialCapital;
    }

    public double getCurrentCapital() {
        return currentCapital;
    }

    public void setCurrentCapital(double currentCapital) {
        this.currentCapital = currentCapital;
    }

    public double calculateProfit() {
        return currentCapital - initialCapital;
    }

    @Override
    public String toString() {
        return super.toString() + "\nOwner Name: " + ownerName + "\nInitial Capital: " + initialCapital + "\nCurrent Capital: " + currentCapital;
    }
}
