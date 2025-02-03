#include <stdio.h>
#include "Tasks.h"

void fcTask2(void)
{
    printf("Perform task 2\n");
    int h, m, h_new, m_new;

    printf("Enter the current time (hours and minutes): ");
    scanf("%d:%d", &h, &m);

    m_new = m + 15;
    h_new = h + (m_new >= 60 ? 1 : 0);
    h_new = h_new % 24;
    m_new = m_new % 60;

    printf("The time after 15 minutes will be: %02d:%02d\n", h_new, m_new);

}
