#include <stdio.h>
#include "Tasks.h"

int findLongestPlatform(int arr[], int n) {
    int maxLength = 1, currentLength = 1;

    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i-1]) {
            currentLength++;
        } else {
            currentLength = 1;
        }

        if (currentLength > maxLength) {
            maxLength = currentLength;
        }
    }

    return maxLength;
}

void fcTask1(void)
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int longestPlatform = findLongestPlatform(arr, n);
    printf("The longest platform has a length of %d\n", longestPlatform);
}
