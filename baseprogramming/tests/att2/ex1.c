#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct IceCream {
    char code[3];
    char name[21];
    float weight;
    float pricePerKg;
};

float totalPriceByLetter(struct IceCream *creams, int n, char letter);
int writeToFile(struct IceCream *creams, int n, float price, float weight);
void printInfo(const char *code);

bool isValidCode(const char *code) {
    if (strlen(code) != 2)
        return false;

    if (!isupper(code[0]))
        return false;

    if (!isdigit(code[1]))
        return false;

    return true;
}

float totalPriceByLetter(struct IceCream *creams, int n, char letter) {
    float total = 0.0;

    for (int i = 0; i < n; i++) {
        if (creams[i].name[0] == letter) {
            float creamPrice = creams[i].weight * creams[i].pricePerKg;
            total += creamPrice;
        }
    }
    return total;
}

int writeToFile(struct IceCream *creams, int n, float price, float weight) {
    int count = 0;
    FILE *file = fopen("info.txt", "a");
    if (file == NULL) {
        perror("ERR");
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        if (creams[i].pricePerKg < price && creams[i].weight > weight) {
            fprintf(file, "%s;%s;%.2lfleva\n", creams[i].code, creams[i].name, creams[i].weight, creams[i].pricePerKg);
            count++;
        }
    }
    fclose(file);
    return count;
}

void printInfo(const char *code) {
    FILE *file = fopen("icecream.bin", "rb");
    if (file == NULL) {
        perror("Err");
        return;
    }

    struct IceCream cream;

    while (fread(&cream, sizeof(struct IceCream), 1, file) == 1) {
        if (strcmp(cream.code, code) == 0) {
            printf("Ice Cream Code: %s\n", cream.code);
            printf("Name: %s\n", cream.name);
            printf("Weight: %.2f kg\n", cream.weight);
            printf("Price per kg: %.2f\n", cream.pricePerKg);
            fclose(file);
            return;
        }
    }
    printf("cream w/ code not found\n");
    fclose(file);
}

int main() {
    int n;
    printf("enter creams 6>n<14\n");
    scanf("%d", &n);
    if (n < 6 || n > 14) {
        printf("invalid");
        return 1;
    }

    struct IceCream *creams = (struct IceCream *)malloc(n * sizeof(struct IceCream));
    if (creams == NULL) {
        printf("memory fail\n");
        return 1;
    }

    printf("enter info for creams\n");
    for (int i = 0; i < n; i++) {
        printf("cream %d:\n", i+1);
        printf("code: ");
        scanf("%2s", creams[i].code);
        if (!isValidCode(creams[i].code)) {
            printf("invalid");
            return 1;
        }
        printf("enter name: ");
        scanf(" %20[^\n]", creams[i].name);
        printf("weight: ");
        scanf("%f", &creams[i].weight);
        printf("priceperkg: ");
        scanf("%f", &creams[i].pricePerKg);
    }

    printf("\ninfo:\n");
    for (int i = 0; i < n; ++i) {
        printf("Ice Cream %d:\n", i + 1);
        printf("Code: %s\n", creams[i].code);
        printf("Name: %s\n", creams[i].name);
        printf("Weight: %.2f kg\n", creams[i].weight);
        printf("Price per kg: $%.2f\n", creams[i].pricePerKg);
    }
    free(creams);
    return 0;
}
