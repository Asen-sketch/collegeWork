#include <stdio.h>
#include <string.h>

struct Pet {
    char name[31];
    char chipNumber[9];
    double examinationFee;
};

#define MAX_PATIENTS 100

struct Pet patients[MAX_PATIENTS];
int patientCount = 0;

void addPatient() {
    if (patientCount < MAX_PATIENTS) {
        printf("Enter pet's name (max 30 characters): ");
        scanf("%30s", patients[patientCount].name);

        printf("Enter chip number (format A12345B): ");
        scanf("%8s", patients[patientCount].chipNumber);

        printf("Enter examination fee: ");
        scanf("%lf", &patients[patientCount].examinationFee);

        FILE *file = fopen("animalsText.txt", "a");
        if (file != NULL) {
            fprintf(file, "%s,%.2lf\n", patients[patientCount].name, patients[patientCount].examinationFee);
            fclose(file);
        } else {
            printf("Unable to open file for writing!\n");
        }

        patientCount++;
    } else {
        printf("Maximum number of patients reached!\n");
    }
}

void printPatientsByFee(struct Pet arr[], int size, double fee) {
    int found = 0;
    printf("Patients with examination fee %.2lf:\n", fee);
    for (int i = 0; i < size; ++i) {
        if (arr[i].examinationFee == fee) {
            printf("Name: %s, Chip Number: %s\n", arr[i].name, arr[i].chipNumber);
            found = 1;
        }
    }
    if (!found) {
        printf("No patients found with examination fee %.2lf\n", fee);
    }
}

int main() {
    addPatient();

    double feeToSearch;
    printf("Enter examination fee to search for: ");
    scanf("%lf", &feeToSearch);
    printPatientsByFee(patients, patientCount, feeToSearch);

    return 0;
}
