#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int N;
    printf("Enter the number of integers: ");
    scanf("%d", &N);

    FILE *file = fopen("numbers.bin", "wb");
    if (file == NULL) {
        printf("Error creating file.");
        return 1;
    }

    fwrite(&N, sizeof(int), 1, file);

    printf("Enter %d integers:\n", N);
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);
        fwrite(&num, sizeof(int), 1, file);
    }

    fclose(file);
    printf("File created successfully.\n");

    file = fopen("numbers.bin", "rb");
    if (file == NULL) {
        printf("Error opening file.");
        return 1;
    }

    fread(&N, sizeof(int), 1, file);

    int evenCount = 0, oddCount = 0;
    for (int i = 0; i < N; i++) {
        int num;
        fread(&num, sizeof(int), 1, file);
        if (num % 2 == 0) {
            evenCount++;
        } else {
            oddCount++;
        }
    }

    fclose(file);

    printf("Number of even numbers: %d\n", evenCount);
    printf("Number of odd numbers: %d\n", oddCount);

    file = fopen("numbers.bin", "rb");
    if (file == NULL) {
        printf("Error opening binary file.");
        return 1;
    }

    fread(&N, sizeof(int), 1, file);

    int *numbers = malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        fread(&numbers[i], sizeof(int), 1, file);
    }

    fclose(file);

    qsort(numbers, N, sizeof(int), compare);

    FILE *txtFile = fopen("sorted_numbers.txt", "w");
    if (txtFile == NULL) {
        printf("Error creating text file.");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        fprintf(txtFile, "%d ", numbers[i]);
    }

    fclose(txtFile);
    free(numbers);

    printf("Sorted array written to sorted_numbers.txt\n");

    return 0;
}
