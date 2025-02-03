#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

struct IceCream {
    char code[3];
    char name[21];
    int kg;
    double priceKg;
};

bool isValidCode(const char *code) {
    if (strlen(code) != 2 || !isdigit(code[1]) || !isupper(code[0]))
        return false;

    return true;
}

int main() {
    int n = 0;
    printf("Enter num of cream! (between 5 and 15, not including): ");
    scanf("%d", &n);
    if (n < 6 || n > 14) {
        printf("INVALID\n");
        return 1;
    }

    struct IceCream *creams = (struct IceCream *)malloc(n * sizeof(struct IceCream));
    if (creams == NULL) {
        printf("MEMORY FAIL\n");
        return 1;
    }

    printf("enter info for each cream\n");
    for (int i = 0; i < n; i++) {
        printf("Ice Cream %d:\n", i+1);
        printf("Code: ");
        scanf("%2s", creams[i].code);
        if (!isValidCode(creams[i].code))
            return 1;
        printf("Name: ");
        scanf(" %20[^\n]", creams[i].name);
        printf("Weight: ");
        scanf("%d", &creams[i].kg);
        printf("Price/KG: ");
        scanf("%lf", &creams[i].priceKg);
    }

    free(creams);
    return 0;
}

int searchByLetter(struct IceCream *creams, int n, char letter) {
    double total = 0.0;
    for (int i = 0; i < n; i++) {
        if (creams[i].name[0] == letter) {
            float price = creams[i].kg * creams[i].priceKg;
            total += price;
        }
    }
    return total;
}

int writeToFile(struct IceCream *creams, int n, double price, int weight) {
    int count = 0;
    FILE *file = fopen("info.txt", "a");
    if (file == NULL) {
        perror("ERR");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (creams[i].priceKg < price && creams[i].kg > weight) {
            fprintf(file, "%s;%s;%d;%lfleva\n", creams[i].code, creams[i].name, creams[i].kg, creams[i].priceKg);
            count++;
        }
    }
    fclose(file);
    return count;
}

void printInfo(const char *code) {
    FILE *file = fopen("icecream.bin", "rb");
    if (file == NULL) {
        perror("ERR");
        return;
    }

    struct IceCream cream;

    while (fread(&cream, sizeof(struct IceCream), 1, file) == 1) {
        if (strcmp(cream.code, code) == 0) {
            printf("==============\n");
            printf("cream - %s\n", cream.name);
            printf("price - %lf\n", cream.priceKg);
            printf("==============\n");
            fclose(file);
            return;
        }
    }
    printf("cream w/code not found\n");
    fclose(file);
}
