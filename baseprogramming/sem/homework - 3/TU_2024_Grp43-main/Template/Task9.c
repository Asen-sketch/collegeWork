#include <stdio.h>
#include "Tasks.h"

void fcTask9(void)
{
    double area, grape_per_sq_meter, desired_wine;
    const double grape_for_wine = 2.5;
    const double worker_share_percentage = 0.5;

    printf("Perform task 9\n");


    printf("Enter the area of the vineyard (in square meters): ");
    scanf("%lf", &area);
    printf("Enter the grape yield per square meter (in kilograms): ");
    scanf("%lf", &grape_per_sq_meter);
    printf("Enter the desired quantity of wine (in liters): ");
    scanf("%lf", &desired_wine);

    double total_grape_yield = area * grape_per_sq_meter;

    double wine_production = (total_grape_yield * 0.4) / grape_for_wine;

    printf("Wine production: %.2f liters\n", wine_production);

    if (wine_production >= desired_wine) {
        printf("The wine production is sufficient.\n");

        double remaining_wine = wine_production - desired_wine;
        double worker_share = remaining_wine * worker_share_percentage;

        printf("Each worker gets: %.2f liters of wine.\n", worker_share);
    } else {
        printf("The wine production is insufficient.\n");
    }
}
