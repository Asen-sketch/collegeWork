#include <stdio.h>
#include <stdbool.h>

#define N 3
#define M 4

bool is_sorted_ascending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
}

bool is_sorted_descending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] < arr[i + 1]) {
            return false;
        }
    }
    return true;
}

void fcTask1(void) {
    int arr[N][M] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    bool is_sorted = true;

    for (int i = 0; i < N; i++) {
        if (!is_sorted_ascending(arr[i], M)) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        printf("All rows are sorted in ascending order.\n");
    } else {
        printf("Not all rows are sorted in ascending order.\n");
    }

    for (int i = 0; i < M; i++) {
        int col[M];
        for (int j = 0; j < N; j++) {
            col[j] = arr[j][i];
        }
        if (!is_sorted_descending(col, N)) {
            is_sorted = false;
            break;
        }
    }

    if (is_sorted) {
        printf("All columns are sorted in descending order.\n");
    } else {
        printf("Not all columns are sorted in descending order.\n");
    }

}
