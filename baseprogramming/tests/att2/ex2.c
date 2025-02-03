#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define FILE_NAME "animalsText.txt"

struct Patient {
    char ownerName[31];
    char chipNumber[8];
    double examPrice;
};

void addPatient();
void printbyPrice(struct Patient patients[], int size, double examPrice);
void printbyPriceBin(double examPrice);

struct Patient patients[100];
int numPatients = 0;
int size = sizeof(patients) / sizeof(patients[0]);

bool isValidChipNumber(const char *chipNumber) {
    if (strlen(chipNumber) != 7)
        return false;

    if (!isalpha(chipNumber[0]))
        return false;

    if (!isalpha(chipNumber[6]))
        return false;

    for (int i = 1; i <= 5; ++i) {
        if (!isdigit(chipNumber[i]))
            return false;
    }

    return true;
}

void addPatient() {
    if (numPatients < 100) {
        struct Patient newPatient;
        printf("Enter owner's name (up to 30 characters): ");
        scanf("%30[^\n]", newPatient.ownerName);

        printf("Enter chip ('A12345B'): ");
        scanf("%7s", newPatient.chipNumber);
        if (!isValidChipNumber(newPatient.chipNumber)) {
            printf("Invalid chip number!\n");
            return;
        }

        printf("Enter Exam. price: ");
        scanf("%lf", &newPatient.examPrice);
        getchar();

        FILE *file = fopen(FILE_NAME, "a");
        if (file != NULL) {
            fprintf(file, "%s,%.2lf\n", newPatient.ownerName, newPatient.examPrice);
            fclose(file);
            printf("Success!\n");
        } else {
            printf("Unable to open file\n");
        }

        patients[numPatients++] = newPatient;
    } else {
        printf("MAX PATIENTS REACHED\n");
    }
}


void printbyPrice(struct Patient patients[], int size, double examPrice) {
    int found = 0;
    printf("Patients with exam price %.2lf:\n", examPrice);
    for (int i = 0; i < size; ++i) {
        if (patients[i].examPrice == examPrice) {
            printf("%s - %s\n", patients[i].ownerName, patients[i].chipNumber);
            found = 1;
        }
    }
    if (!found) {
        printf("None found.");
    }
}

void printbyPriceBin(double examPrice) {
    FILE *file = fopen("animalsBin.bin", "rb");
    if (file == NULL) {
        printf("ERR: Unable to open");
        return;
    }

    struct Patient patient;
    printf("Result: ");
    while (fread(&patient, sizeof(struct Patient), 1, file) == 1) {
        if (patient.examPrice >= examPrice) {
            printf("Name: %s, Chip: %s\n", patient.ownerName, patient.chipNumber);
        }
    }

    fclose(file);
}

int main() {
    addPatient();
    printbyPrice(patients, size, 20);

    return 0;
}
