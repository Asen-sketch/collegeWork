#include <stdio.h>

int main() {
    int num1, num2, sum1 = 0;
    int sum2 = 1;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int smaller = (num1 < num2) ? num1 : num2;
    int larger = (num1 > num2) ? num1 : num2;

    for (int i = smaller + 1; i < larger; i++) {
        if (i % 2 == 0) {
            sum1 += i;
        } else {
            sum2 *= i;
        }
    }

    printf("Sum of even nums between %d and %d: %d\n", num1, num2, sum1);
    printf("Multiplication of odd nums between %d and %d: %d\n", num1, num2, sum2);


    return 0;
}
