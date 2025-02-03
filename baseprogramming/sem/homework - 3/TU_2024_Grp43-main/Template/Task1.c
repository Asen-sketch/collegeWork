#include <stdio.h>

int get_max(int num1, int num2) {
    return (num1 > num2) ? num1 : num2;
}

int get_min(int num1, int num2) {
    return (num1 < num2) ? num1 : num2;
}

void fcTask1(void) {
    printf("Perform task 1\n");
    int num, max_num = -2147483648, min_num = 2147483647;

    printf("Enter numbers (enter 0 to stop):\n");

    while (1) {
        scanf("%d", &num);

        if (num == 0)
            break;

        max_num = get_max(max_num, num);
        min_num = get_min(min_num, num);
    }

    printf("Maximum entered number: %d\n", max_num);
    printf("Minimum entered number: %d\n", min_num);

}
