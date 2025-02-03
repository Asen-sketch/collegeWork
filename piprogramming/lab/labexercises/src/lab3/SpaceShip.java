package lab3;

abstract class SpaceShip implements Fly {
    protected String type;
    protected double speed;
    protected double cargoCapacity;
    protected double weaponPower;

    public SpaceShip(String type, double speed, double cargoCapacity, double weaponPower) {
        this.type = type;
        this.speed = speed;
        this.cargoCapacity = cargoCapacity;
        this.weaponPower = weaponPower;
    }

    public abstract void travel(double x, double y, double z);
    public abstract void harvestResource(Planet planet);
    public abstract void attack(SpaceObject target);

    @Override
    public void flyTo(SpaceObject destination) {
        System.out.println(type + " is flying to " + destination.name);
    }
}

class Scout extends SpaceShip {
    private double sensorRange;

    public Scout(double speed, double sensorRange) {
        super("Scout", speed, 0, 0);
        this.sensorRange = sensorRange;
    }

    @Override
    public void travel(double x, double y, double z) {
        System.out.println("Scout is traveling at speed " + speed + " to coordinates (" + x + ", " + y + ", " + z + ").");
    }

    public void flyTo(SpaceObject destination) {
        System.out.println("Scout is flying to " + destination.name);
    }

    @Override
    public void harvestResource(Planet planet) {
        System.out.println("Scout cannot harvest resources.");
    }

    @Override
    public void attack(SpaceObject target) {
        System.out.println("Scout cannot attack.");
    }

    public void explore(Planet planet) {
        System.out.println("Exploring around planet " + planet.getName() + " within a sensor range of " + sensorRange);
    }

    public void reportResources(Planet planet) {
        System.out.println("Scout report for " + planet.getName() + ":");
        planet.printResources();
    }

}

