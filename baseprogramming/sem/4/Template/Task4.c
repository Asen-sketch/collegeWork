#include <stdio.h>

#define MAX_PEOPLE 100

void fcTask4(void) {
    int friends[MAX_PEOPLE][MAX_PEOPLE] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 0},
        {0, 0, 1, 0, 0}
    };

    printf("Enter the person to query for friends: ");
    int queryPerson;
    scanf("%d", &queryPerson);

    printf("Friends of person %d: ", queryPerson);
    for (int i = 0; i < MAX_PEOPLE; i++) {
        if (friends[queryPerson][i] == 1) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
