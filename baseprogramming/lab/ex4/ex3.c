#include <stdio.h>

int main() {
    int numbers[7];
    int sum = 0;

    printf("Enter 7 nums:\n");
    for (int i = 0; i < 7; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
        sum += numbers[i];
    }

    float average = (float)sum / 7;

    printf("Average: %.2f\n", average);

    return 0;
}
