package ex2;

import static ex2.Car.*;

public class Main {
    public static void main(String[] args) {
        CompanyET etCompany = new CompanyET("et1", "2022-05-10", "B123456789", "owner", 10000.0, 15000.0);

        //System.out.println(etCompany);

        double profit = etCompany.calculateProfit();
        System.out.println("Profit: " + profit);

        // ex1 ^ - ex 2 v

        Car car1 = new Car("Toyota", "Corolla", "Red", 130, "Gasoline", "Manual", 2018);
        Car car2 = new Car("Tesla", "Model 3", "Black", 300, "Electric", "Automatic", 2020);
        Car car3 = new Car("BMW", "X5", "White", 250, "Diesel", "Automatic", 2019);

        Car[] carArray = { car1, car2, car3, car1 };

        Car[] filteredCars = filterCarsByBrand(carArray, 'T');
        System.out.println("Cars starting with 'T':");
        for (Car car : filteredCars) {
            System.out.println(car);
        }

        Car[] sortedCarsAsc = sortCarsByBrand(carArray, true);
        System.out.println("\nCars sorted by brand (ascending):");
        for (Car car : sortedCarsAsc) {
            System.out.println(car);
        }

        Car[] sortedCarsDesc = sortCarsByBrand(carArray, false);
        System.out.println("\nCars sorted by brand (descending):");
        for (Car car : sortedCarsDesc) {
            System.out.println(car);
        }

        Car[] uniqueCars = removeDuplicateCars(carArray);
        System.out.println("\nUnique cars:");
        for (Car car : uniqueCars) {
            System.out.println(car);
        }
    }
}
