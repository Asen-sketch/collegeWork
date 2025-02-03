#include <stdio.h>
#include <stdlib.h>

int* input(int *count);
void output(int *array, int count);
void sort(int *array, int count);
int sum(int *array, int start, int end);

int main() {
    int choice;
    int count = 0;
    int *array = NULL;

    do {
        printf("Menu:\n");
        printf("1-Input\n");
        printf("2-Output\n");
        printf("3-Sort\n");
        printf("4-Sum in Range\n");
        printf("5-Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                array = input(&count);
                break;
            case 2:
                if (array != NULL) {
                    output(array, count);
                    _getch();
                } else {
                    printf("Array is empty. Please input some numbers first.\n");
                    _getch();
                }
                break;
            case 3:
                if (array != NULL) {
                    sort(array, count);
                    printf("Array sorted successfully.\n");
                    _getch();
                } else {
                    printf("Array is empty. Please input some numbers first.\n");
                    _getch();
                }
                break;
            case 4:
                if (array != NULL) {
                    int start, end;
                    printf("Enter start index: ");
                    scanf("%d", &start);
                    printf("Enter end index: ");
                    scanf("%d", &end);
                    printf("Sum in range: %d\n", sum(array, start, end));
                    _getch();
                } else {
                    printf("Array is empty. Please input some numbers first.\n");
                    _getch();
                }
                break;
            case 5:
                if (array != NULL) {
                    free(array);
                }
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
                _getch();
        }
        system("cls");
    } while (1);

    return 0;
}

int* input(int *count) {
    int *array = NULL;
    int size = 1;
    int num;

    printf("Enter numbers (0 to end input):\n");
    array = (int*)malloc(sizeof(int) * size);
    if (array == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    while (1) {
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        array[*count] = num;
        (*count)++;
        if (*count >= size) {
            size *= 2;
            array = (int*)realloc(array, sizeof(int) * size);
            if (array == NULL) {
                printf("Memory reallocation failed.\n");
                exit(1);
            }
        }
    }

    return array;
}

void output(int *array, int count) {
    printf("Array elements:\n");
    for (int i = 0; i < count; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void sort(int *array, int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int sum(int *array, int start, int end) {
    int sum = 0;
    for (int i = start; i <= end; i++) {
        sum += array[i];
    }
    return sum;
}
