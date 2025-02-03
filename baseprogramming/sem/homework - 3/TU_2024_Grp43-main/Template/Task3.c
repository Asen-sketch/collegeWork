#include <stdio.h>
#include "Tasks.h"

void fcTask3(void)
{
    printf("Perform task 3\n");
    int num1, num2, num3;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    if (num1 == num2 && num2 == num3) {
        printf("The numbers are equal.\n");
    } else {
        printf("The numbers are not equal.\n");
    }

}
