#include <stdio.h>
#include "Tasks.h"

void fcTask5(void)
{
    printf("Perform task 5\n");
    int time1, time2, time3, total_minutes, total_seconds;

    printf("Enter the time of athlete 1 in seconds: ");
    scanf("%d", &time1);
    printf("Enter the time of athlete 2 in seconds: ");
    scanf("%d", &time2);
    printf("Enter the time of athlete 3 in seconds: ");
    scanf("%d", &time3);

    total_seconds = time1 + time2 + time3;

    total_minutes = total_seconds / 60;

    total_seconds = total_seconds % 60;

    printf("Total time: %d:%02d\n", total_minutes, total_seconds);
}
