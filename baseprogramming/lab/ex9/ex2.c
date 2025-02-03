#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    FILE *file = fopen("numbers.bin", "wb");
    if (file == NULL) {
        printf("Error creating file.");
        return 1;
    }

    int num;
    printf("Enter integers (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &num);
        if (num == -1)
            break;
        fwrite(&num, sizeof(int), 1, file);
    }

    fclose(file);
    printf("File created successfully.\n");

    file = fopen("numbers.bin", "rb");
    if (file == NULL) {
        printf("Error opening file.");
        return 1;
    }

    int evenCount = 0, oddCount = 0;
    while (fread(&num, sizeof(int), 1, file) == 1) {
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

    fseek(file, 0, SEEK_END);
    long fileSize = ftell(file);
    rewind(file);
    int numCount = fileSize / sizeof(int);

    int *numbers = malloc(numCount * sizeof(int));
    if (numbers == NULL) {
        printf("Memory allocation failed.");
        return 1;
    }

    fread(numbers, sizeof(int), numCount, file);
    fclose(file);

    qsort(numbers, numCount, sizeof(int), compare);

    FILE *txtFile = fopen("sorted_numbers2.txt", "w");
    if (txtFile == NULL) {
        printf("Error creating text file.");
        free(numbers);
        return 1;
    }

    for (int i = 0; i < numCount; i++) {
        fprintf(txtFile, "%d ", numbers[i]);
    }

    fclose(txtFile);
    free(numbers);

    printf("Sorted array written to sorted_numbers2.txt\n");

    return 0;
}
