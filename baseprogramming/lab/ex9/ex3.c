#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Car {
    char brand[50];
    char model[6];
    float engineCapacity;
    float price;
    char registration;
};

void writeBinary(const struct Car *car) {
    FILE *file = fopen("car_data.bin", "ab");
    if (file == NULL) {
        printf("Error opening binary file for writing.");
        return;
    }
    fwrite(car, sizeof(struct Car), 1, file);
    fclose(file);
}

void writeText(const struct Car *car) {
    FILE *file = fopen("car_data.txt", "a");
    if (file == NULL) {
        printf("Error opening text file for writing.");
        return;
    }
    fprintf(file, "%s %s %.2f %.2f %c\n", car->brand, car->model, car->engineCapacity, car->price, car->registration);
    fclose(file);
}

void addCar() {
    struct Car car;
    printf("Enter car brand: ");
    scanf("%s", car.brand);
    printf("Enter car model (up to 5 characters): ");
    scanf("%s", car.model);
    printf("Enter engine capacity: ");
    scanf("%f", &car.engineCapacity);
    printf("Enter price: ");
    scanf("%f", &car.price);
    printf("Is the car registered? (Y/N): ");
    scanf(" %c", &car.registration);

    writeBinary(&car);
    writeText(&car);
    printf("Car added successfully.\n");
}

void readAndDisplay() {
    struct Car car;
    printf("Car data from binary file:\n");
    FILE *binaryFile = fopen("car_data.bin", "rb");
    if (binaryFile == NULL) {
        printf("Error opening binary file for reading.\n");
    } else {
        while (fread(&car, sizeof(struct Car), 1, binaryFile) == 1) {
            printf("%s %s %.2f %.2f %c\n", car.brand, car.model, car.engineCapacity, car.price, car.registration);
        }
        fclose(binaryFile);
    }

    printf("\nCar data from text file:\n");
    FILE *textFile = fopen("car_data.txt", "r");
    if (textFile == NULL) {
        printf("Error opening text file for reading.\n");
    } else {
        while (fscanf(textFile, "%s %s %f %f %c", car.brand, car.model, &car.engineCapacity, &car.price, &car.registration) == 5) {
            printf("%s %s %.2f %.2f %c\n", car.brand, car.model, car.engineCapacity, car.price, car.registration);
        }
        fclose(textFile);
    }
}

int main() {
    int choice;
    do {
        printf("\n1. Add a new car\n");
        printf("2. Read and display car data\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addCar();
                break;
            case 2:
                readAndDisplay();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
