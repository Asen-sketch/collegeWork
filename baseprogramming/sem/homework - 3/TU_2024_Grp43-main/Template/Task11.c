#include <stdio.h>
#include "Tasks.h"

//imah zatrudneniq

void fcTask11(void)
{
    printf("Perform task 11\n");

    int width;
    printf("Enter the width of the castle: ");
    scanf("%d", &width);

    if (width < 3) {
        printf("Width must be at least 3.\n");
        return 1;
    }

    printf("/");
    for (int i = 0; i < width - 2; i++) {
        printf("^");
    }
    printf("\\____/");
    for (int i = 0; i < width - 2; i++) {
        printf("^");
    }
    printf("\\\n");

    for (int i = 0; i < width - 2; i++) {
        printf("|");
        for (int j = 0; j < 2 * width - 3; j++) {
            printf("  ");
        }
        printf("|\n");
    }

    printf("|");
    for (int i = 0; i < width / 2; i++) {
        printf("  ");
    }
    printf("____");
    for (int i = 0; i < width / 2; i++) {
        printf("   ");
    }
    printf("|\n");
    printf("\\____/");
    for (int i = 0; i < width - 2; i++) {
        printf(" ");
    }
    printf("\\____/\n");
}
