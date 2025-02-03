#include <stdio.h>
#include "Tasks.h"

void fcTask6(void)
{
    double x1, y1, x2, y2, x, y;

    printf("Perform task 6\n");
    printf("Enter the coordinates of the rectangle (x1, y1, x2, y2): ");
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    printf("Enter the coordinates of the point (x, y): ");
    scanf("%lf %lf", &x, &y);

    if ((x >= x1 && x <= x2) && (y >= y1 && y <= y2)) {
        printf("Inside\n");
    } else {
        printf("Outside\n");
    }
}
