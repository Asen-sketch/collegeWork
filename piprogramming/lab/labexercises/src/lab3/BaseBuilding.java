package lab3;

public abstract class BaseBuilding {
    protected String name;
    protected int level;
    protected int constructionTime;
    protected double metalRequired;
    protected double crystalRequired;
    protected double gasRequired;
    protected double uraniumRequired;

    public BaseBuilding(String name, int level, int constructionTime, double metalRequired, double crystalRequired, double gasRequired, double uraniumRequired) {
        this.name = name;
        this.level = level;
        this.constructionTime = constructionTime;
        this.metalRequired = metalRequired;
        this.crystalRequired = crystalRequired;
        this.gasRequired = gasRequired;
        this.uraniumRequired = uraniumRequired;
    }

    public String getName() {
        return name;
    }

    public int getLevel() {
        return level;
    }

    public void upgrade() {
        level++;
    }

    public abstract void applyEffect(Planet planet);
}

class MetalMine extends BaseBuilding {
    public MetalMine() {
        super("Metal Mine", 1, 0, 100, 50, 0, 0);
    }

    @Override
    public void applyEffect(Planet planet) {
        planet.increaseMetalProduction(level);
    }
}

class CrystalMine extends BaseBuilding {
    public CrystalMine() {
        super("Crystal Mine", 1, 0, 50, 100, 0, 0);
    }

    @Override
    public void applyEffect(Planet planet) {
        planet.increaseCrystalProduction(level);
    }
}

class GasRefinery extends BaseBuilding {
    public GasRefinery() {
        super("Gas Refinery", 1, 5, 50, 50, 100, 0);
    }

    @Override
    public void applyEffect(Planet planet) {
        planet.increaseGasProduction(level);
    }
}

class ResearchLab extends BaseBuilding {
    public ResearchLab() {
        super("Research Lab", 1, 10, 100, 100, 100, 50);
    }

    @Override
    public void applyEffect(Planet planet) {
        planet.increaseResearchRate(level);
    }
}

class ShipYard extends BaseBuilding {
    public ShipYard() {
        super("Ship Yard", 1, 15, 200, 150, 100, 50);
    }

    @Override
    public void applyEffect(Planet planet) {
        planet.increaseShipProduction(level);
    }
}
