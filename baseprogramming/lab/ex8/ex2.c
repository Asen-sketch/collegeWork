#include <stdio.h>
#include <string.h>

// Structure for a vehicle
struct Vehicle {
    char make[50];
    char model[50];
    int year;
    float price;
};

// Structure for different types of vehicles
struct Car {
    struct Vehicle base;
    int doors;
};

struct Motorcycle {
    struct Vehicle base;
    int cylinders;
};

struct Boat {
    struct Vehicle base;
    float length;
};

struct Airplane {
    struct Vehicle base;
    int engines;
};

int compareByPrice(const void *a, const void *b) {
    const struct Vehicle *vehicleA = (const struct Vehicle *)a;
    const struct Vehicle *vehicleB = (const struct Vehicle *)b;
    return (vehicleA->price > vehicleB->price) - (vehicleA->price < vehicleB->price);
}

int main() {
    struct Car car = {{"Toyota", "Corolla", 2020, 25000}, 4};
    struct Motorcycle motorcycle = {{"Honda", "CBR500R", 2019, 7000}, 2};
    struct Boat boat = {{"Sea Ray", "Sundancer", 2015, 150000}, 28.5};
    struct Airplane airplane = {{"Boeing", "737", 2018, 85000000}, 2};

    struct Vehicle vehicles[] = {car.base, motorcycle.base, boat.base, airplane.base};
    int numVehicles = sizeof(vehicles) / sizeof(vehicles[0]);

    qsort(vehicles, numVehicles, sizeof(struct Vehicle), compareByPrice);

    printf("Vehicles sorted by price:\n");
    for (int i = 0; i < numVehicles; i++) {
        printf("%s %s - $%.2f\n", vehicles[i].make, vehicles[i].model, vehicles[i].price);
    }

    return 0;
}
