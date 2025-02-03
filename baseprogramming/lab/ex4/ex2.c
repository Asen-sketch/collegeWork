#include <stdio.h>

int main() {
    int numbers[7];
    int max;

    printf("Enter 7 nums:\n");
    for (int i = 0; i < 7; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    max = numbers[0];
    for (int i = 1; i < 7; i++) {
        if (numbers[i] > max) {
            max = numbers[i];
        }
    }

    printf("Biggest number: %d\n", max);

    return 0;
}
