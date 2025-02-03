#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store information about ice creams
struct IceCream {
    char code[3]; // Unique code (combination of uppercase letter and digit, e.g., "A2")
    char name[21]; // Product name (string of 20 characters)
    float weight; // Weight stored in kilograms
    float pricePerKg; // Price per kilogram (format: real number 0.00)
};

void printIceCreamByCode(char *code) {
    FILE *file = fopen("icecream.bin", "rb"); // Open binary file for reading
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct IceCream iceCream; // Temporary variable to hold ice cream data read from file

    // Read ice cream records from the file until the end
    while (fread(&iceCream, sizeof(struct IceCream), 1, file) == 1) {
        // Check if the code matches the requested code
        if (strcmp(iceCream.code, code) == 0) {
            // Print ice cream information
            printf("Ice Cream Code: %s\n", iceCream.code);
            printf("Name: %s\n", iceCream.name);
            printf("Weight: %.2f kg\n", iceCream.weight);
            printf("Price per kg: $%.2f\n", iceCream.pricePerKg);
            fclose(file); // Close the file
            return;
        }
    }

    // If the loop completes without finding a matching code, print a message
    printf("No ice cream found with code '%s'.\n", code);
    fclose(file); // Close the file
}

// Function to write ice cream information to a file
int writeIceCreamInfoToFile(struct IceCream iceCreams[], int n, float price, float weight) {
    FILE *file = fopen("info.txt", "w"); // Open file for writing
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    int count = 0; // Count of records written to the file

    // Iterate through the ice creams
    for (int i = 0; i < n; i++) {
        // Check if the price is lower and weight is higher than specified parameters
        if (iceCreams[i].pricePerKg < price && iceCreams[i].weight > weight) {
            // Write ice cream information to the file
            fprintf(file, "%s;%s;%.2fkg%.2flv\n", iceCreams[i].code, iceCreams[i].name, iceCreams[i].weight, iceCreams[i].pricePerKg);
            count++;
        }
    }

    fclose(file); // Close the file
    return count;
}

int main() {
    int n;

    // Prompt user to input the number of ice creams
    printf("Enter the number of ice creams (between 5 and 15): ");
    scanf("%d", &n);

    // Check if n is within the specified range
    if (n < 5 || n > 15) {
        printf("Invalid input! Number of ice creams must be between 5 and 15.\n");
        return 1; // Exit with error
    }

    // Allocate memory for the dynamic array of IceCream structs
    struct IceCream *iceCreams = (struct IceCream *)malloc(n * sizeof(struct IceCream));

    // Check if memory allocation was successful
    if (iceCreams == NULL) {
        printf("Memory allocation failed!\n");
        return 1; // Exit with error
    }

    // Prompt user to input data for each ice cream
    printf("Enter data for each ice cream:\n");
    for (int i = 0; i < n; i++) {
        printf("\nIce Cream %d:\n", i + 1);
        printf("Enter code (e.g., A1): ");
        scanf("%s", iceCreams[i].code); // Assuming input format is correct
        printf("Enter name (up to 20 characters): ");
        scanf("%20s", iceCreams[i].name);
        printf("Enter weight in kilograms: ");
        scanf("%f", &iceCreams[i].weight);
        printf("Enter price per kilogram: ");
        scanf("%f", &iceCreams[i].pricePerKg);
    }

    // Displaying the data for verification
    printf("\nIce Creams:\n");
    for (int i = 0; i < n; i++) {
        printf("Ice Cream %d:\n", i + 1);
        printf("Code: %s\n", iceCreams[i].code);
        printf("Name: %s\n", iceCreams[i].name);
        printf("Weight: %.2f kg\n", iceCreams[i].weight);
        printf("Price per kg: $%.2f\n", iceCreams[i].pricePerKg);
    }

    // Prompt user to input price and weight criteria
    float price, weight;
    printf("\nEnter the price (in format 0.00): ");
    scanf("%f", &price);
    printf("Enter the weight: ");
    scanf("%f", &weight);

    // Write ice cream information to file based on given criteria
    int recordsWritten = writeIceCreamInfoToFile(iceCreams, n, price, weight);
    if (recordsWritten > 0) {
        printf("\n%d records were written to info.txt\n", recordsWritten);
    } else {
        printf("\nNo records matching the criteria were found.\n");
    }

    // Free dynamically allocated memory
    free(iceCreams);

    return 0; // Exit success
}
