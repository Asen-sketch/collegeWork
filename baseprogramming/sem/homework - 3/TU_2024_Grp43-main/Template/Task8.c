#include <stdio.h>
#include "Tasks.h"

void calculate_pool_state(int volume, int pipe1_rate, int pipe2_rate, int hours) {
    int pipe1_water = pipe1_rate * hours;
    int pipe2_water = pipe2_rate * hours;

    int total_water = pipe1_water + pipe2_water;

    if (total_water <= volume) {
        printf("The pool is partially filled.\n");
        printf("The total water in the pool: %d liters\n", total_water);
    } else {
        printf("The pool is fully filled.\n");
        printf("The excess water: %d liters\n", total_water - volume);
    }
}

void fcTask8(void)
{
    int volume, pipe1_rate, pipe2_rate, hours;

    printf("Perform task 8\n");

    printf("Enter the volume of the pool (in liters): ");
    scanf("%d", &volume);
    printf("Enter the rate of water flow for the first pipe (in liters per hour): ");
    scanf("%d", &pipe1_rate);
    printf("Enter the rate of water flow for the second pipe (in liters per hour): ");
    scanf("%d", &pipe2_rate);
    printf("Enter the number of hours the worker is away: ");
    scanf("%d", &hours);

    calculate_pool_state(volume, pipe1_rate, pipe2_rate, hours);
}
