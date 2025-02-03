#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char name[21];
    int code;
    char expiry[11]; //yyyy.mm.dd
    float price;
} Product;

bool isValidCount(int n) {
    return n > 10 && n < 30;
}

bool isValidCode(int code) {
    return code >= 100 && code <= 999;
}

bool isValidExpiry(const char* expiry) {
    int yr, m, d;
    return sscanf(expiry, "%4d.%2d.%2d", &yr, &m, &d) == 3 && yr > 999 && m >= 1 && m <= 12 && d <= 31;
}

bool isEarlier(const char* date1, const char* date2) {
    int y1, y2, m1, m2, d1, d2;
    sscanf(date1, "%4d.%2d.%2d", &y1, &m1, &d1);
    sscanf(date2, "%4d.%2d.%2d", &y2, &m2, &d2);
    if (y1 < y2) return true;
    if (y1 > y2) return false;
    if (m1 < m2) return true;
    if (m1 > m2) return false;
    return d1 < d2;
}

float avrg_by_price(Product* prods, int size, float price) {
    int count = 0;
    float pricesum = 0.0;
    for (int i = 0; i < size; i++)  {
        if (prods[i].price < price) {
            price += prods[i].price;
            count++;
        }
    }
    if (count == 0) {
        return 0.0;
    }
    return pricesum/count;
}

int write_text_file(Product* prods, int size, const char* date) {
    int count = 0;
    FILE* file = fopen("products.txt", "w");
    if (!file) {
        perror("file open fail");
        return -1;
    }

    for (int i = 0; i < size; i++) {
        if(isEarlier(prods[i].expiry, date)) {
           count++;
           fprintf("%s-%d-%s-%.2f", prods[i].name, &prods[i].code, prods[i].expiry, &prods[i].price);
        }
    }

    fclose(file);
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
    int n;
    printf("enter amount of products (10-30): ");
    scanf("%d", &n);
    if (n < 10 || n > 30) {
        printf("invalid count");
        return -1;
    }

    Product* prods = (Product*)malloc(n * sizeof(Product));
    if (prods == NULL) {
        perror("memory alloc fail");
        return -1;
    }

    for (int i = 0; i < n; i++) {
        printf("entering info for product %d", i+1);
        printf("name: ");
        scanf("%20s", prods[i].name);
        printf("code: ");
        scanf("%3d", &prods[i].code);
        if (!isValidCode(prods[i].code)) {
            printf("invalid");
            free(prods);
            return -1;
        }
        printf("expiry (yyyy.mm.dd): ");
        scanf("%10s", prods[i].expiry);
        if (!isValidExpiry(prods[i].expiry)) {
            printf("invalid");
            free(prods);
            return -1;
        }
        printf("price: ");
        scanf("%f", &prods[i].price);
    }

    free(prods);
    return 0;
}
