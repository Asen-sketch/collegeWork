#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct IceCream {
    char code[3];
    char name[21];
    float weight;
    float pricePerKg;
};

float totalPriceByLetter(struct IceCream *iceCreams, int n, char letter);
int writeToFile(struct IceCream *iceCreams, int n, float price, float weight);
void printInfo(const char *code);

bool isValidCodeFormat(const char *code) {
    if (strlen(code) != 2)
        return false;

    if (!isupper(code[0]))
        return false;

    if (!isdigit(code[1]))
        return false;

    return true;
}

float totalPriceByLetter(struct IceCream *iceCreams, int n, char letter) {
    float totalPrice = 0.0;

    for (int i = 0; i < n; i++) {
        if (iceCreams[i].name[0] == letter) {
            float iceCreamPrice = iceCreams[i].weight * iceCreams[i].pricePerKg;
            totalPrice += iceCreamPrice;
        }
    }

    return totalPrice;
}

int writeToFile(struct IceCream *iceCreams, int n, float price, float weight) {
    int count = 0;
    FILE *file = fopen("info.txt", "a");

    if (file == NULL) {
        perror("Error opening file");
        return 0;
    }

    for (int i = 0; i < n; i++) {
        if (iceCreams[i].pricePerKg < price && iceCreams[i].weight > weight) {
            fprintf(file, "%s;%s;%.2f%.2fлв.\n", iceCreams[i].code, iceCreams[i].name,
                    iceCreams[i].weight, iceCreams[i].pricePerKg);
            count++;
        }
    }

    fclose(file);
    return count;
}

void printInfo(const char *code) {
    FILE *file = fopen("icecream.bin", "rb");

    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    struct IceCream iceCream;

    while (fread(&iceCream, sizeof(struct IceCream), 1, file) == 1) {
        if (strcmp(iceCream.code, code) == 0) {
            printf("Ice Cream Code: %s\n", iceCream.code);
            printf("Name: %s\n", iceCream.name);
            printf("Weight: %.2f kg\n", iceCream.weight);
            printf("Price per kg: %.2f\n", iceCream.pricePerKg);
            fclose(file);
            return;
        }
    }
    printf("Ice cream with code %s not found.\n", code);
    fclose(file);
}

int main() {
    int n;

    printf("Enter the number of ice creams (between 5 and 15): ");
    scanf("%d", &n);

    if (n < 6 || n > 14) {
        printf("Invalid input! Number of ice creams must be between 5 and 15, not including.\n");
        return 1;
    }

    struct IceCream *iceCreams = (struct IceCream *)malloc(n * sizeof(struct IceCream));

    if (iceCreams == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter information for each ice cream:\n");
    for (int i = 0; i < n; i++) {
        printf("Ice Cream %d:\n", i + 1);

        printf("Enter code (e.g., A2): ");
        scanf("%2s", iceCreams[i].code);
        if (!isValidCodeFormat(iceCreams[i].code)) {
            printf("INVALID");
            return 1;
        }

        printf("Enter name (up to 20 characters): ");
        scanf(" %30[^\n]", iceCreams[i].name);

        printf("Enter weight in kilograms: ");
        scanf("%f", &iceCreams[i].weight);

        printf("Enter price per kilogram: ");
        scanf("%f", &iceCreams[i].pricePerKg);
    }

    printf("\nIce Cream Information:\n");
    for (int i = 0; i < n; i++) {
        printf("Ice Cream %d:\n", i + 1);
        printf("Code: %s\n", iceCreams[i].code);
        printf("Name: %s\n", iceCreams[i].name);
        printf("Weight: %.2f kg\n", iceCreams[i].weight);
        printf("Price per kg: $%.2f\n", iceCreams[i].pricePerKg);
    }
    free(iceCreams);

    return 0;
}
