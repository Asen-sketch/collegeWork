#include <stdio.h>

int main() {
    int num, sum = 0;

    printf("Enter nums (0 when done!): ");

    while (1) {
        scanf("%d", &num);
        if (num == 0) {
            break;
        }
        sum += num;
    }

    printf("Sum of nums: %d\n", sum);

    return 0;
}
