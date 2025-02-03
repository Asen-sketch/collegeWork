package lab3;

// Resource.java

public class Resource {
    protected double amount;
    protected double harvestRate;

    public Resource(double amount, double harvestRate) {
        this.amount = amount;
        this.harvestRate = harvestRate;
    }

    public void harvest() {
        amount += harvestRate;
    }

    public double getAmount() {
        return amount;
    }

    public void setHarvestRate(double harvestRate) {
        this.harvestRate = harvestRate;
    }

    public double getHarvestRate() {
        return harvestRate;
    }

    @Override
    public String toString() {
        return "Amount: " + amount + ", Harvest Rate: " + harvestRate;
    }
}

class Metal extends Resource {
    public Metal(double amount) {
        super(amount, 1.0);
    }

    public void upgradeMetalMine(int level) {
        harvestRate *= Math.pow(2, level);
    }
}

class Gas extends Resource {
    public Gas(double amount) {
        super(amount, 0.5);
    }

    public void upgradeGasRefinery(int level) {
        harvestRate *= Math.pow(2, level);
    }
}

class Crystal extends Resource {
    public Crystal(double amount) {
        super(amount, 0.2);
    }

    public void upgradeCrystalMine(int level) {
        harvestRate *= Math.pow(2, level);
    }
}

class Uranium extends Resource {
    public Uranium(double amount) {
        super(amount, 0.1);
    }

    public void upgradeUraniumMine(int level) {
        harvestRate *= Math.pow(2, level);
    }
}

