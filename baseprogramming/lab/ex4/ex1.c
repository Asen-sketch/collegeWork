#include <stdio.h>

int main() {
    int numbers[7];
    int sum = 0;

    printf("Enter 7 nums:\n");
    for (int i = 0; i < 7; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    for (int i = 0; i < 7; i++) {
        sum += numbers[i];
    }

    printf("Sum: %d\n", sum);

    return 0;
}
