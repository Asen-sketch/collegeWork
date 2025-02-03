#include <stdio.h>
#include <limits.h>

#define N 3
#define M 3

int max_neighbor_sum(int arr[N][M], int *max_sum_row, int *max_sum_col) {
    int max_sum = INT_MIN;
    int row, col;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int sum = 0;
            for (int k = i - 1; k <= i + 1; k++) {
                for (int l = j - 1; l <= j + 1; l++) {
                    if (k >= 0 && k < N && l >= 0 && l < M && (k != i || l != j)) {
                        sum += arr[k][l];
                    }
                }
            }
            sum += arr[i][j];

            if (sum > max_sum) {
                max_sum = sum;
                row = i;
                col = j;
            }
        }
    }

    *max_sum_row = row;
    *max_sum_col = col;
    return max_sum;
}

void fcTask2(void) {
    int arr[N][M] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int max_sum_row, max_sum_col;

    int max_sum = max_neighbor_sum(arr, &max_sum_row, &max_sum_col);

    printf("The maximum sum of neighboring elements is: %d\n", max_sum);
    printf("The position of the number is: (%d, %d)\n", max_sum_row, max_sum_col);
}
