#include <stdio.h>
#include "Tasks.h"

void circularShift(int arr[], int N, int K) {
    K = K % N;
    if (K < 0) {
        K += N;
    }

    int temp[N];

    for (int i = 0; i < N; i++) {
        temp[(i + K) % N] = arr[i];
    }

    for (int i = 0; i < N; i++) {
        arr[i] = temp[i];
    }
}

void fcTask4(void)
{
    printf("Executing task 4;\n");
        int N, K;
    printf("Enter the size of the sequence: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter the elements of the sequence: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the value of K: ");
    scanf("%d", &K);

    circularShift(arr, N, K);

    printf("Sequence after circular shift: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
