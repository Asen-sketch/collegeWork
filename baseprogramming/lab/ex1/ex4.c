#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two integers: ");
    scanf("%d", &a);
    scanf("%d", &b);

    if (a > b) {
        printf("\n%d is bigger than %d\n", a, b);
    } else if (a < b) {
        printf("\n%d is smaller than %d\n", a, b);
    } else {
        printf("\n%d and %d are equal\n", a, b);
    }

    return 0;
}
