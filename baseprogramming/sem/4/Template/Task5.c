#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void addElement(int **arr, int *size, int element) {
    (*size)++;
    *arr = (int *)realloc(*arr, *size * sizeof(int));
    (*arr)[(*size) - 1] = element;
}

void deleteElement(int **arr, int *size, int element) {
    int newSize = 0;
    for (int i = 0; i < *size; i++) {
        if ((*arr)[i] != element) {
            (*arr)[newSize] = (*arr)[i];
            newSize++;
        }
    }
    *size = newSize;
    *arr = (int *)realloc(*arr, *size * sizeof(int));
}

int findMinElement(int *arr, int size) {
    int minElement = INT_MAX;
    for (int i = 0; i < size; i++) {
        if (arr[i] < minElement) {
            minElement = arr[i];
        }
    }
    return minElement;
}

void printArray(int *arr, int size) {
    printf("Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void fcTask5(void) {
    int *arr = NULL;
    int size = 0;
    int choice, element;

    do {
        printf("\nMenu:\n");
        printf("1. Add element\n");
        printf("2. Delete element and all its occurrences\n");
        printf("3. Find the smallest element\n");
        printf("4. Print the array\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to add: ");
                scanf("%d", &element);
                addElement(&arr, &size, element);
                printf("Element added successfully.\n");
                break;
            case 2:
                printf("Enter the element to delete: ");
                scanf("%d", &element);
                deleteElement(&arr, &size, element);
                printf("Element and all its occurrences deleted successfully.\n");
                break;
            case 3:
                if (size > 0) {
                    int minElement = findMinElement(arr, size);
                    printf("The smallest element in the array is: %d\n", minElement);
                } else {
                    printf("Array is empty.\n");
                }
                break;
            case 4:
                if (size > 0) {
                    printArray(arr, size);
                } else {
                    printf("Array is empty.\n");
                }
                break;
            case 5:
                printf("Exiting program...\n");
                break;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 5);

    free(arr);
}
