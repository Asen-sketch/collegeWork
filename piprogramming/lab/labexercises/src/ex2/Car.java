package ex2;

public class Car {
    private String brand;
    private String model;
    private String color;
    private int horsePower;
    private String engineType;
    private String transmission;
    private int yop;

    public Car(String brand, String model, String color, int horsepower, String engineType, String transmission, int yearOfProduction) {
        this.brand = brand;
        this.model = model;
        this.color = color;
        this.horsePower = horsepower;
        this.engineType = engineType;
        this.transmission = transmission;
        this.yop = yearOfProduction;
    }

    public Car() {}

    public String getBrand() {
        return brand;
    }

    public void setBrand(String brand) {
        this.brand = brand;
    }

    public String getModel() {
        return model;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public int getHorsepower() {
        return horsePower;
    }

    public void setHorsepower(int horsepower) {
        this.horsePower = horsepower;
    }

    public String getEngineType() {
        return engineType;
    }

    public void setEngineType(String engineType) {
        this.engineType = engineType;
    }

    public String getTransmission() {
        return transmission;
    }

    public void setTransmission(String transmission) {
        this.transmission = transmission;
    }

    public int getYop() {
        return yop;
    }

    public void setYop(int yearOfProduction) {
        this.yop = yearOfProduction;
    }

    @Override
    public String toString() {
        return brand + " " + model + " (" + yop + "), Color: " + color + ", " + horsePower + " HP, " + engineType + ", " + transmission;
    }

    public static Car[] filterCarsByBrand(Car[] cars, char letter) {
        int count = 0;
        for (Car car : cars) {
            if (car.getBrand().toUpperCase().charAt(0) == Character.toUpperCase(letter)) {
                count++;
            }
        }

        Car[] filteredCars = new Car[count];
        int index = 0;

        for (Car car : cars) {
            if (car.getBrand().toUpperCase().charAt(0) == Character.toUpperCase(letter)) {
                filteredCars[index++] = car;
            }
        }

        return filteredCars;
    }

    public static Car[] sortCarsByBrand(Car[] cars, boolean ascending) {
        int n = cars.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (ascending) {
                    if (cars[j].getBrand().compareTo(cars[j + 1].getBrand()) > 0) {
                        Car temp = cars[j];
                        cars[j] = cars[j + 1];
                        cars[j + 1] = temp;
                    }
                } else {
                    if (cars[j].getBrand().compareTo(cars[j + 1].getBrand()) < 0) {
                        Car temp = cars[j];
                        cars[j] = cars[j + 1];
                        cars[j + 1] = temp;
                    }
                }
            }
        }
        return cars;
    }

    public static Car[] removeDuplicateCars(Car[] cars) {
        Car[] uniqueCars = new Car[cars.length];
        int uniqueCount = 0;

        for (int i = 0; i < cars.length; i++) {
            boolean isDuplicate = false;

            for (int j = 0; j < uniqueCount; j++) {
                if (cars[i].getBrand().equals(uniqueCars[j].getBrand()) &&
                        cars[i].getModel().equals(uniqueCars[j].getModel()) &&
                        cars[i].getYop() == uniqueCars[j].getYop()) {
                    isDuplicate = true;
                    break;
                }
            }

            if (!isDuplicate) {
                uniqueCars[uniqueCount++] = cars[i];
            }
        }

        Car[] result = new Car[uniqueCount];
        for (int i = 0; i < uniqueCount; i++) {
            result[i] = uniqueCars[i];
        }

        return result;
    }


}
