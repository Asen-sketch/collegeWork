#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IceCream {
    char code[3];
    char name[21];
    float weight;
    float pricePerKg;
};

float totalPriceByLetter(struct IceCream iceCreams[], int n, char letter) {
    float totalPrice = 0.0;

    for (int i = 0; i < n; i++) {
        if (iceCreams[i].name[0] == letter) {
            totalPrice += iceCreams[i].weight * iceCreams[i].pricePerKg;
        }
    }

    return totalPrice;
}

int writeIceCreamInfoToFile(struct IceCream iceCreams[], int n, float price, float weight) {
    FILE *file = fopen("info.txt", "w");
    if (file == NULL) {
        printf("Error opening file!\n");
        return 0;
    }

    int count = 0;

    for (int i = 0; i < n; i++) {
        if (iceCreams[i].pricePerKg < price && iceCreams[i].weight > weight) {
            fprintf(file, "%s;%s;%.2fkg%.2flv\n", iceCreams[i].code, iceCreams[i].name, iceCreams[i].weight, iceCreams[i].pricePerKg);
            count++;
        }
    }

    fclose(file);
    return count;
}

void printIceCreamByCode(char *code) {
    FILE *file = fopen("icecream.bin", "rb");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    struct IceCream iceCream;

    while (fread(&iceCream, sizeof(struct IceCream), 1, file) == 1) {
        if (strcmp(iceCream.code, code) == 0) {
            printf("Ice Cream Code: %s\n", iceCream.code);
            printf("Name: %s\n", iceCream.name);
            printf("Weight: %.2f kg\n", iceCream.weight);
            printf("Price per kg: $%.2f\n", iceCream.pricePerKg);
            fclose(file);
            return;
        }
    }

    printf("No ice cream found with code '%s'.\n", code);
    fclose(file);
}

int main() {
    int n;

    printf("Enter the number of ice creams (between 5 and 15): ");
    scanf("%d", &n);

    if (n < 6 || n > 14) {
        printf("Invalid input! Number of ice creams must be between 5 and 15.\n");
        return 1;
    }

    struct IceCream *iceCreams = (struct IceCream *)malloc(n * sizeof(struct IceCream));

    if (iceCreams == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter data for each ice cream:\n");
    for (int i = 0; i < n; i++) {
        printf("\nIce Cream %d:\n", i + 1);
        printf("Enter code (e.g., A1): ");
        scanf("%s", iceCreams[i].code);
        printf("Enter name (up to 20 characters): ");
        scanf("%20s", iceCreams[i].name);
        printf("Enter weight in kilograms: ");
        scanf("%f", &iceCreams[i].weight);
        printf("Enter price per kilogram: ");
        scanf("%f", &iceCreams[i].pricePerKg);
    }

    printf("\nIce Creams:\n");
    for (int i = 0; i < n; i++) {
        printf("Ice Cream %d:\n", i + 1);
        printf("Code: %s\n", iceCreams[i].code);
        printf("Name: %s\n", iceCreams[i].name);
        printf("Weight: %.2f kg\n", iceCreams[i].weight);
        printf("Price per kg: $%.2f\n", iceCreams[i].pricePerKg);
    }

    char letter;
    printf("\nEnter the starting letter of ice cream names to calculate total price: ");
    scanf(" %c", &letter);

    float total = totalPriceByLetter(iceCreams, n, letter);
    if (total > 0) {
        printf("\nTotal price of ice creams whose name starts with '%c': $%.2f\n", letter, total);
    } else {
        printf("\nNo ice creams found with names starting with '%c'. Total price: $0.00\n", letter);
    }

    free(iceCreams);

    return 0;
}
