#include <stdio.h>

int max(int num1, int num2);

int main() {
    int x, y;

    printf("Enter x: ");
    scanf("%d", &x);
    printf("Enter y: ");
    scanf("%d", &y);

    printf("Max: %d\n", max(x, y));

    return 0;
}

int max(int num1, int num2) {
    int res;
    if (num1 > num2) {
        res = num1;
    } else {
        res = num2;
    }
    return res;
}
