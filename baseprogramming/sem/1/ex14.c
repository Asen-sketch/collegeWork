#include <stdio.h>

int main() {
    double veg_price_per_kg, fruit_price_per_kg;
    int total_kg_veg, total_kg_fruit;
    double total_income_lv, total_income_eur;

    printf("enter the price per kilogram of vegetables: ");
    scanf("%lf", &veg_price_per_kg);

    printf("enter the price per kilogram of fruits: ");
    scanf("%lf", &fruit_price_per_kg);

    printf("enter the total kilograms of vegetables: ");
    scanf("%d", &total_kg_veg);

    printf("enter the total kilograms of fruits: ");
    scanf("%d", &total_kg_fruit);

    total_income_lv = (veg_price_per_kg * total_kg_veg) + (fruit_price_per_kg * total_kg_fruit);

    total_income_eur = total_income_lv / 1.95;

    printf("total income in euro: %.2lf\n", total_income_eur);

    return 0;
}
