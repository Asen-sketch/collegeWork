#include <stdio.h>
#include "Tasks.h"

void reverseArray(int arr[], int N) {
    int start = 0;
    int end = N - 1;

    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

void fcTask3(void)
{
    printf("Executing task 3;");
    int N;
    printf("Enter the size of the array: ");
    scanf("%d", &N);

    int arr[N];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }

    reverseArray(arr, N);

    printf("Reversed array: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
