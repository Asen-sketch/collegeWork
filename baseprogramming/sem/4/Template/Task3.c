#include <stdio.h>
#include <limits.h>

#define N 4
#define M 5

void swap_rows(int arr[N][M], int min_row, int max_row) {
    int temp[M];

    for (int i = 0; i < M; i++) {
        temp[i] = arr[min_row][i];
        arr[min_row][i] = arr[max_row][i];
        arr[max_row][i] = temp[i];
    }
}

void find_min_max_rows(int arr[N][M], int *min_row, int *max_row) {
    int min_val = INT_MAX, max_val = INT_MIN;

    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = 0; j < M; j++) {
            sum += arr[i][j];
        }

        if (sum < min_val) {
            min_val = sum;
            *min_row = i;
        }

        if (sum > max_val) {
            max_val = sum;
            *max_row = i;
        }
    }
}

void fcTask3(void) {
    int arr[N][M] = {{1, 2, 3, 4, 5}, {6, 7, 8, 9, 10}, {11, 12, 13, 14, 15}, {16, 17, 18, 19, 20}};

    int min_row = 0, max_row = 0;

    find_min_max_rows(arr, &min_row, &max_row);

    if (min_row != max_row) {
        swap_rows(arr, min_row, max_row);
    }

    printf("Array after swapping rows with minimum and maximum sums:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

}
