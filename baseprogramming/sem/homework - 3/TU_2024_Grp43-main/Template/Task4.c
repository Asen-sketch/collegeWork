#include <stdio.h>
#include "Tasks.h"

void fcTask4(void)
{
    printf("Perform task 4\n");
    int points, bonus_points = 0, additional_bonus = 0;

    printf("Enter the number of points: ");
    scanf("%d", &points);

    if (points <= 100) {
        bonus_points = 5;
    } else if (points <= 1000) {
        bonus_points = (int)(0.2 * points);
    } else {
        bonus_points = (int)(0.1 * points);
    }

    if (points % 2 == 0) {
        additional_bonus = 1;
    }
    if (points % 10 == 5) {
        additional_bonus += 2;
    }

    printf("Bonus points: %d\n", bonus_points);
    printf("Total points with bonus points: %d\n", points + bonus_points + additional_bonus);
}
