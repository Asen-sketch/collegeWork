#include <stdio.h>
#include "Tasks.h"

//imah zatrudneniq

void fcTask12(void)
{
    int width;

    printf("Perform task 12\n");

    printf("Enter the width of the butterfly: ");
    scanf("%d", &width);

    if (width < 3 || width % 2 == 0) {
        printf("Width must be an odd number greater than or equal to 3.\n");
        return;
    }

    int middle = width / 2;

    printf("***");
    for (int i = 0; i < middle - 1; ++i) {
        printf("\\ ");
    }
    printf("/***\n");

    printf("---");
    for (int i = 0; i < middle - 1; ++i) {
        printf("/ ");
    }
    printf("\\---\n");

    printf("***");
    for (int i = 0; i < middle - 1; ++i) {
        printf("\\ ");
    }
    printf("/***\n");

    for (int i = 0; i < middle; ++i) {
        printf(" ");
    }
    printf("  @\n");

    printf("***");
    for (int i = 0; i < middle - 1; ++i) {
        printf("/ ");
    }
    printf("\\***\n");

    printf("---");
    for (int i = 0; i < middle - 1; ++i) {
        printf("\\ ");
    }
    printf("/---\n");

    printf("***");
    for (int i = 0; i < middle - 1; ++i) {
        printf("/ ");
    }
    printf("\\***\n");
}
