package sem4;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

class NoAvailableNightsException extends Exception {
    public NoAvailableNightsException(String message) {
        super(message);
    }
}

abstract class Room {
    private int roomNumber;
    private String roomType;
    private double pricePerNight;
    private int availableNights;

    public Room(int roomNumber, String roomType, double pricePerNight, int availableNights) {
        this.roomNumber = roomNumber;
        this.roomType = roomType;
        this.pricePerNight = pricePerNight;
        this.availableNights = availableNights;
    }

    public boolean reserveRoom(int numNights) throws NoAvailableNightsException {
        if (numNights > availableNights) {
            throw new NoAvailableNightsException("Not enough nights available for room " + roomNumber);
        }
        availableNights -= numNights;
        return true;
    }

    public int getRoomNumber() {
        return roomNumber;
    }

    public String getRoomType() {
        return roomType;
    }

    public double getPricePerNight() {
        return pricePerNight;
    }

    public int getAvailableNights() {
        return availableNights;
    }

    @Override
    public String toString() {
        return "Room{" +
                "roomNumber=" + roomNumber +
                ", roomType='" + roomType + '\'' +
                ", pricePerNight=" + pricePerNight +
                ", availableNights=" + availableNights +
                '}';
    }
}

class SingleRoom extends Room {
    private String bedCategory;

    public SingleRoom(int roomNumber, double pricePerNight, int availableNights, String bedCategory) {
        super(roomNumber, "Single", pricePerNight, availableNights);
        this.bedCategory = bedCategory;
    }

    public String getBedCategory() {
        return bedCategory;
    }

    @Override
    public String toString() {
        return super.toString() + ", BedCategory='" + bedCategory + "'";
    }
}

class SuiteRoom extends Room {
    private int numberOfRooms;

    public SuiteRoom(int roomNumber, double pricePerNight, int availableNights, int numberOfRooms) {
        super(roomNumber, "Suite", pricePerNight, availableNights);
        this.numberOfRooms = numberOfRooms;
    }

    public int getNumberOfRooms() {
        return numberOfRooms;
    }

    @Override
    public String toString() {
        return super.toString() + ", NumberOfRooms=" + numberOfRooms;
    }
}

class InvalidRoomDataException extends Exception {
    public InvalidRoomDataException(String message) {
        super(message);
    }
}

interface Reservable {
    void updateAvailabilityFromFile() throws IOException, InvalidRoomDataException;
}

class RoomLoader implements Reservable {
    private String fileName;
    private List<Room> rooms = new ArrayList<>();

    public RoomLoader(String fileName) {
        this.fileName = fileName;
    }

    public List<Room> getRooms() {
        return rooms;
    }

    @Override
    public void updateAvailabilityFromFile() throws IOException, InvalidRoomDataException {
        try (BufferedReader reader = new BufferedReader(new FileReader(fileName))) {
            String line;
            while ((line = reader.readLine()) != null) {
                String[] parts = line.split("\\*");
                if (parts.length != 5) {
                    throw new InvalidRoomDataException("Invalid room data format: " + line);
                }

                try {
                    int type = Integer.parseInt(parts[0]);
                    int roomNumber = Integer.parseInt(parts[1]);
                    double price = Double.parseDouble(parts[3]);
                    int availableNights = Integer.parseInt(parts[4]);

                    if (type == 1) {
                        rooms.add(new SingleRoom(roomNumber, price, availableNights, "Standard Bed"));
                    } else if (type == 2) {
                        rooms.add(new SuiteRoom(roomNumber, price, availableNights, 2));
                    } else {
                        throw new InvalidRoomDataException("Unknown room type: " + line);
                    }
                } catch (NumberFormatException e) {
                    throw new InvalidRoomDataException("Invalid number format in line: " + line);
                }
            }
        } catch (FileNotFoundException e) {
            throw new IOException("File not found: " + fileName, e);
        }
    }
}

class RoomBookingSystem {
    public static Room[] singleRooms;
    public static Room[] suiteRooms;

    public static void processRoomReservations() {
        RoomLoader loader = new RoomLoader("rooms.txt");

        try {
            loader.updateAvailabilityFromFile();
            List<Room> rooms = loader.getRooms();

            List<Room> singles = new ArrayList<>();
            List<Room> suites = new ArrayList<>();

            for (Room room : rooms) {
                if (room instanceof SingleRoom) {
                    singles.add(room);
                } else if (room instanceof SuiteRoom) {
                    suites.add(room);
                }
            }

            singleRooms = singles.toArray(new Room[0]);
            suiteRooms = suites.toArray(new Room[0]);

            System.out.println("Single Rooms:");
            for (Room single : singleRooms) {
                System.out.println(single);
            }

            System.out.println("Suite Rooms:");
            for (Room suite : suiteRooms) {
                System.out.println(suite);
            }

        } catch (IOException | InvalidRoomDataException e) {
            System.err.println("Error processing room reservations: " + e.getMessage());
        }
    }

    public static void main(String[] args) {
        processRoomReservations();
    }
}