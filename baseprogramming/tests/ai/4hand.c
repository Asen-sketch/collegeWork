#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[21];
    int code;
    char expiry[11];
    float price;
} Product;

bool isValidCode(int code) {
    return code >= 100 && code <= 999;
}

bool isValidCount (int count) {
    return count >= 10 && count <= 30;
}

bool isValidExpiry(const char* expiry) {
    int yr, m, d;
    return sscanf(expiry, "%2d.%2d.%4d", &d, &m, &yr) == 3 && yr > 0 && m >= 1 && m <= 12 && d <= 31;
}

bool isEarlier(const char* date1, const char* date2) {
    int y1, y2, m1, m2, d1, d2;
    sscanf(date1, "%2d.%2d.%4d", &d1, &m1, &y1);
    sscanf(date2, "%2d.%2d.%4d", &d2, &m2, &y2);
    if (y1 < y2) return true;
    if (y1 > y2) return false;
    if (m1 < m2) return true;
    if (m1 > m2) return false;
    return d1 < d2;
}

float avrg_by_price(Product* prods, int size, float price) {
    int count = 0;
    float sum = 0.0;

    for (int i = 0; i < size; i++) {
        if (prods[i].price < price) {
            sum += prods[i].price;
            count++;
        }
    }

    if (count == 0) {
        return 0.0;
    }

    return sum/count;
}

int wite_text_file(Product* prods, int size, const char* date, float price) {
    FILE* file = fopen("products.txt", "w");
    if (!file) {
        perror("open fail");
        return 0;
    }

    int count = 0;

    for (int i = 0; i < size; i++) {
        if (isEarlier(prods[i].expiry, date)) {
            fprintf(file, "%s-%d-%s-%.2f leva\n", prods[i].name, prods[i].code, prods[i].expiry, prods[i].price);
            count++;
        }
    }
    if (fclose(file) != 0) {
        perror("close fail");
        return 0;
    }
    return count;
}

void print_info(const char* search_name, int search_code) {
    FILE* file = fopen("product.bin", "rb");
    if (!file) {
        perror("open fail");
        return;
    }

    bool found = false;

    while (true) {
        int length;
        if (fread(&length, sizeof(int), 1, file) != 1) break;

        char name[21];
        if (length > 20) {
            fprintf(stderr, "err - name too long\n");
            break;
        }
        if (fread(name, sizeof(char), length, file) != length) break;

        int code;
        if (fread(&code, sizeof(int), 1, file) != 1) break;

        char expiry[11];
        if (fread(expiry, sizeof(char), 10, file) != 10) break;

        float price;
        if (fread(&price, sizeof(float), 1, file) != 1) break;

        if (strcmp(name, search_name) == 0 && code == search_code) {
            printf("data for prod: %s - use before %s - price %.2f leva\n", name, expiry, price);
            found = true;
            break;
        }
    }
    if (!found) {
        printf("not found");
    }
    if (fclose(file) != 0) {
        perror("fail to close file");
    }
}

int main() {
    int n = 0;
    printf("enter n: (10-30)");
    scanf("%d", &n);
    if (!isValidCount(n)) {
        printf("invalid");
        return 1;
    }

    Product* prods = (Product*)malloc(n * sizeof(Product));
    if (!prods) {
        perror("alloc fail");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("enter details for %d:\n", i+1);
        printf("name: ");
        scanf("%20s", prods[i].name);
        do {
            printf("expiry (dd.mm.yyyy): ");
            scanf("%10s", prods[i].expiry);
            if (!isValidExpiry(prods[i].expiry)) {
                printf("invalid");
            }
        } while (!isValidExpiry(prods[i].expiry));

        printf("price: ");
        scanf("%f", &prods[i].price);
    }

    free(prods);
    return 0;
}
