#include <stdio.h>
#include "Tasks.h"

int lis(int arr[], int n) {
    int dp[n];
    int i, j, max = 0;

    for (i = 0; i < n; i++)
        dp[i] = 1;

    for (i = 1; i < n; i++) {
        for (j = 0; j < i; j++) {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    for (i = 0; i < n; i++)
        if (max < dp[i])
            max = dp[i];

    return max;
}

void fcTask6(void)
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Length of lis is %d\n", lis(arr, n));
}
