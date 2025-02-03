#include <stdio.h>

int main() {
    int num1, num2, sum = 0;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int smaller = (num1 < num2) ? num1 : num2;
    int larger = (num1 > num2) ? num1 : num2;

    for (int i = smaller + 1; i < larger; i++) {
        sum += i;
    }

    printf("Sum of nums between %d and %d: %d\n", num1, num2, sum);

    return 0;
}
