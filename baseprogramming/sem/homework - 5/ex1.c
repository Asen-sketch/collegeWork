#include <stdio.h>
#include <string.h>

#define CHAIR_PRICE 13.99
#define TABLE_PRICE 42.00
#define CUPS_PRICE 5.98
#define DISHES_PRICE 21.02

int main() {
    int guests, total_guests = 0, chairs = 0, tables = 0, cups = 0, dishes = 0;
    double total_cost = 0.0;
    char item[20];

    scanf("%d", &guests);

    while (scanf("%s", item) != EOF) {
        if (strcmp(item, "Chair") == 0) {
            chairs++;
        } else if (strcmp(item, "Table") == 0) {
            tables++;
        } else if (strcmp(item, "Cups") == 0) {
            cups++;
        } else if (strcmp(item, "Dishes") == 0) {
            dishes++;
        } else if (strcmp(item, "PARTY!") == 0) {
            total_guests += guests;
            total_cost += (chairs * CHAIR_PRICE) + (tables * TABLE_PRICE) + (cups * CUPS_PRICE) + (dishes * DISHES_PRICE);

            int additional_chairs = guests - chairs;
            int additional_tables = (total_guests + 4) / 5 - tables;
            int additional_cups = (total_guests + 4) / 5 - cups;
            int additional_dishes = (total_guests + 4) / 5 - dishes;

            printf("%.2lf\n", total_cost);
            printf("%d Table\n", additional_tables);
            printf("%d Chairs\n", additional_chairs);
            printf("%d Cups\n", additional_cups);
            printf("%d Dishes\n", additional_dishes);
            break;
        }
    }

    return 0;
}
