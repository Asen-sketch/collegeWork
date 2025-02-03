#include <stdio.h>

int main() {
    int N;

    printf("Enter the size of the square matrix: ");
    scanf("%d", &N);

    int matrix[N][N];

    printf("Enter %d elements for a %d x %d matrix:\n", N*N, N, N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("Main diagonal elements: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", matrix[i][i]);
    }
    printf("\n");

    printf("Secondary diagonal elements: ");
    for (int i = 0; i < N; i++) {
        printf("%d ", matrix[i][N - 1 - i]);
    }
    printf("\n");

    printf("Elements above the main diagonal:\n");
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    printf("Elements below the main diagonal:\n");
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < i; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
