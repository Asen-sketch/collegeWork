package lab3;

import java.util.ArrayList;
import java.util.List;

abstract class SpaceObject {
    protected String name;
    protected double coordinateX;
    protected double coordinateY;
    protected double coordinateZ;
    protected double mass;

    public SpaceObject(String name, double x, double y, double z, double mass) {
        this.name = name;
        this.coordinateX = x;
        this.coordinateY = y;
        this.coordinateZ = z;
        this.mass = mass;
    }

    public abstract void displayInfo();


}

abstract class OrbitalSpaceObject extends SpaceObject {
    protected List<SpaceObject> orbiters = new ArrayList<>();

    public OrbitalSpaceObject(String name, double x, double y, double z, double mass) {
        super(name, x, y, z, mass);
    }

    public void addOrbiter(SpaceObject orbiter) {
        orbiters.add(orbiter);
    }

    public List<SpaceObject> getOrbiters() {
        return orbiters;
    }
}

class Satellite extends SpaceObject implements Orbiter {
    public Satellite(String name, double x, double y, double z, double mass) {
        super(name, x, y, z, mass);
    }

    @Override
    public void displayInfo() {
        System.out.println("Satellite: " + name);
    }

    @Override
    public void orbit(SpaceObject target) throws NotValidSpaceObjectException {
        if (!(target instanceof Planet)) {
            throw new NotValidSpaceObjectException("A satellite can only orbit a planet.");
        }
        ((Planet) target).addOrbiter(this);
    }
}

class Star extends OrbitalSpaceObject {
    public Star(String name, double x, double y, double z, double mass) {
        super(name, x, y, z, mass);
    }

    @Override
    public void displayInfo() {
        System.out.println("Star: " + name);
    }
}

class Planet extends OrbitalSpaceObject implements Orbiter {
    private List<BaseBuilding> buildings = new ArrayList<>();
    Metal metal;
    Gas gas;
    Crystal crystal;
    Uranium uranium;

    public Planet(String name, double x, double y, double z, double mass) {
        super(name, x, y, z, mass);
        this.metal = new Metal(0);
        this.gas = new Gas(0);
        this.crystal = new Crystal(0);
        this.uranium = new Uranium(0);
    }

    public String getName() {
        return name;
    }

    public void harvestMetal() {
        metal.harvest();
    }

    public void harvestGas() {
        gas.harvest();
    }

    public void harvestCrystal() {
        crystal.harvest();
    }

    public void harvestUranium() {
        uranium.harvest();
    }

    public void printResources() {
        System.out.println("Resources on " + name + ":");
        System.out.println("Metal - " + metal);
        System.out.println("Gas - " + gas);
        System.out.println("Crystal - " + crystal);
        System.out.println("Uranium - " + uranium);
    }

    @Override
    public void displayInfo() {
        System.out.println("Planet: " + name);
    }

    @Override
    public void orbit(SpaceObject target) throws NotValidSpaceObjectException {
        if (!(target instanceof Star)) {
            throw new NotValidSpaceObjectException("A planet can only orbit a star.");
        }
        ((Star) target).addOrbiter(this);
    }
    public void increaseMetalProduction(int level) {
        System.out.println("Metal production increased by " + (level * 10));
    }

    public void increaseCrystalProduction(int level) {
        System.out.println("Crystal production increased by " + (level * 10));
    }

    public void increaseGasProduction(int level) {
        System.out.println("Gas production increased by " + (level * 10));
    }

    public void increaseResearchRate(int level) {
        System.out.println("Research rate increased by " + (level * 5));
    }

    public void increaseShipProduction(int level) {
        System.out.println("Ship production capacity increased by " + (level * 3));
    }

    public void addBuilding(BaseBuilding building) {
        if (metal.getAmount() >= building.metalRequired &&
                crystal.getAmount() >= building.crystalRequired &&
                gas.getAmount() >= building.gasRequired &&
                uranium.getAmount() >= building.uraniumRequired) {

            metal.amount -= building.metalRequired;
            crystal.amount -= building.crystalRequired;
            gas.amount -= building.gasRequired;
            uranium.amount -= building.uraniumRequired;

            buildings.add(building);
            building.applyEffect(this);
            System.out.println(building.getName() + " constructed on " + name);
        } else {
            System.out.println("Not enough resources to construct " + building.getName());
        }
    }
}

class NotValidSpaceObjectException extends Exception {
    public NotValidSpaceObjectException(String message) {
        super(message);
    }
}


