#include <stdio.h>
#include "Tasks.h"

#define INT_MAX 2147483647
#define INT_MIN -2147483648

static int calculate_taxi_cost(int distance) {
    if (distance <= 20) {
        return 70;
    }

    if (distance <= 100) {
        return 70 + 79 * (distance - 20);
    }

    return 70 + 79 * 80 + 90 * (distance - 100);
}

static int calculate_bus_cost(int distance) {
    if (distance < 20) {
        return INT_MAX;
    }

    return 9 * distance;
}

static int calculate_train_cost(int distance) {
    if (distance < 100) {
        return INT_MAX;
    }

    return 6 * distance;
}

void fcTask7(void)
{
    printf("Perform task 7\n");
    printf("Enter the distance in kilometers: ");
    int n;
    scanf("%d", &n);

    int taxi_cost = calculate_taxi_cost(n);
    int bus_cost = calculate_bus_cost(n);
    int train_cost = calculate_train_cost(n);

    int min_cost = INT_MAX;
    char* preferred_transport;

    if (taxi_cost < min_cost) {
        min_cost = taxi_cost;
        preferred_transport = "taxi";
    }

    if (bus_cost < min_cost) {
        min_cost = bus_cost;
        preferred_transport = "bus";
    }

    if (train_cost < min_cost) {
        min_cost = train_cost;
        preferred_transport = "train";
    }

    if (min_cost == INT_MAX) {
        printf("No valid transportation available for the given distance.\n");
    } else {
        printf("The minimum cost for transportation is: %d\n", min_cost);
        printf("Preferred method of travel: %s\n", preferred_transport);
    }
}
