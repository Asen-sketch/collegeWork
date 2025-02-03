#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10

bool isMagical(int matrix[][MAX_SIZE], int size) {
    int sum = 0;

    for (int j = 0; j < size; j++) {
        sum += matrix[0][j];
    }

    for (int i = 1; i < size; i++) {
        int rowSum = 0;
        int colSum = 0;
        for (int j = 0; j < size; j++) {
            rowSum += matrix[i][j];
            colSum += matrix[j][i];
        }
        if (rowSum != sum || colSum != sum) {
            return false;
        }
    }

    return true;
}

int main() {
    int size;

    printf("Enter the size of the square matrix (max %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size < 1 || size > MAX_SIZE) {
        printf("Invalid matrix size.\n");
        return 1;
    }

    int matrix[MAX_SIZE][MAX_SIZE];

    printf("Enter %d elements for a %d x %d matrix:\n", size * size, size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (isMagical(matrix, size)) {
        printf("The matrix is magical!\n");
    } else {
        printf("The matrix is not magical.\n");
    }

    return 0;
}
