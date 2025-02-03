#include <stdio.h>
#include "Tasks.h"

void fcTask10(void)
{
    int n, number;
    int p1 = 0, p2 = 0, p3 = 0, p4 = 0, p5 = 0;

    printf("Perform task 10\n");

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &number);
        if (number < 200) {
            p1++;
        } else if (number < 400) {
            p2++;
        } else if (number < 600) {
            p3++;
        } else if (number < 800) {
            p4++;
        } else {
            p5++;
        }
    }

    double total = p1 + p2 + p3 + p4 + p5;
    p1 = (p1 / total) * 100;
    p2 = (p2 / total) * 100;
    p3 = (p3 / total) * 100;
    p4 = (p4 / total) * 100;
    p5 = (p5 / total) * 100;

    // Print the percentages
    printf("Percentage of numbers below 200: %d%%\n", p1);
    printf("Percentage of numbers between 200 and 399: %d%%\n", p2);
    printf("Percentage of numbers between 400 and 599: %d%%\n", p3);
    printf("Percentage of numbers between 600 and 799: %d%%\n", p4);
    printf("Percentage of numbers 800 and above: %d%%\n", p5);
}
