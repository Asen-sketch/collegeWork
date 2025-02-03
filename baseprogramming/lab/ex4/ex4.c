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
    float min_diff = average - numbers[0];
    int closest = numbers[0];
    int closest_index = 0;

    for (int i = 1; i < 7; i++) {
        float diff = average - numbers[i];
        if (diff < 0) {
            diff = -diff;
        }
        if (diff < min_diff) {
            min_diff = diff;
            closest = numbers[i];
            closest_index = i;
        }
    }

    printf("Average: %.1f\n", average);
    printf("Closest value: %d at position %d\n", closest, closest_index + 1);

    return 0;
}
