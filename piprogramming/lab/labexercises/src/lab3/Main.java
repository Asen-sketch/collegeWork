package lab3;

public class Main {
    public static void main(String[] args) {
        Star sun = new Star("Sun", 0, 0, 0, 1.98930);
        Satellite moonSatellite = new Satellite("Moon Satellite", 384400, 0, 0, 7.3522);

        try {
            moonSatellite.orbit(sun);
        } catch (NotValidSpaceObjectException e) {
            System.out.println("ERR: " + e.getMessage());
        }
    }
}

