#include <stdio.h>

void swap(int *num1, int *num2);

int main() {
    int x = 5, y = 10;

    printf("Before switch: x = %d, y = %d\n", x, y);

    swap(&x, &y);

    printf("After switch: x = %d, y = %d\n", x, y);

    return 0;
}

void swap(int *num1, int *num2) {
    int temp = *num1;
    *num1 = *num2;
    *num2 = temp;
}
