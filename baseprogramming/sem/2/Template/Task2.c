#include <stdio.h>
#include "Tasks.h"

void fcTask2(void)
{
    printf("Executing task 2;\n");
        int N;
    printf("Enter the size of the sequence: ");
    scanf("%d", &N);

    int sequence[N];
    printf("Enter the elements of the sequence: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &sequence[i]);
    }

    int flag = 1;

    for (int i = 0; i < N - 1; i++) {
        if (i % 2 == 0) {
            if (sequence[i] >= sequence[i + 1]) {
                flag = 0;
                break;
            }
        }
        else {
            if (sequence[i] <= sequence[i + 1]) {
                flag = 0;
                break;
            }
        }
    }

    if (flag) {
        printf("The sequence satisfies the relation.\n");
    } else {
        printf("The sequence does not satisfy the relation.\n");
    }
}
