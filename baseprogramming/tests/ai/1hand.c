#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char code[3];
    char name[21];
    int weight;
    float price;
} IceCream;

bool isValidCount(int n) {
    return n > 5 && n < 15;
}

bool isValidCode(const char* code) {
    if (strlen(code) != 2) return false;
    if (!isupper(code[0])) return false;
    if (!isdigit(code[1])) return false;
    return true;
}

int writeByWeight(IceCream* creams, int size, float price, int weight) {
    FILE* file = fopen("info.txt", "w");
    if (!file) {
        perror("err opening file");
        return -1;
    }

    int count = 0;
    for (int i = 0; i < size; i++) {
        if (creams[i].price < price && creams[i].weight > weight) {
            count++;
            fprintf(file, "%s;%s;%d;%.2f leva", creams[i].code, creams[i].name, creams[i].weight, creams[i].price);
        }
    }
    if (fclose(file) != 0) {
        perror("fail closing file");
    }
    return count;
}

void readByCode(const char *code) {
    FILE* file = fopen("icecream.bin", "rb");
    if (!file) {
        perror("no file found");
        return;
    }

    IceCream cream;

    while (fread(&cream, sizeof(IceCream), 1, file) == 1) {
        if (strcmp(cream.code, code) == 0) {
            printf("IceCream - %s\n", cream.name);
            printf("Price - %.2f BGN\n", cream.price);
        }
    }
    if (fclose(file) != 0) {
        perror("err closing file");
    }
}

int main() {
    int n;
    printf("enter size of array (5-15)");
    scanf("%d", &n);
    if (!isValidCount(n)) {
        printf("ERR");
        return -1;
    }

    IceCream* creams = (IceCream*)malloc(n * sizeof(IceCream));
    if (creams == NULL) {
        printf("memory alloc fail");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        printf("entering for cream %d: ", i+1);
        printf("name: ");
        scanf("%20[^\n] ", creams[i].name);
        printf("code (format A1): ");
        scanf("%2s", creams[i].code);
        if (!isValidCode(creams[i].code)) {
            printf("invalid code");
            free(creams);
            return -1;
        }
        printf("weight in kg: ");
        scanf("%d", &creams[i].weight);
        printf("price/kg: ");
        scanf("%f", &creams[i].price);
    }

    free(creams);
    return 0;
}
